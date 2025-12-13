#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<math.h>


/*Generate PRACH input sequence with u=1, length =139;
then correlate with local replica sequences generated with u = 7 and 13; 
compute the correlated power and compare which sequence has high correlation metric */
#define L_RA (139)
#define PI_VAL (3.14)

//correlation output buf
typedef struct {
    double re;
    double im;
}cplx;

typedef struct{
    cplx *inp_seq;
    int u;
    double *corr_out_pwr;
    int corr_len;
}corr_struct;

void gen_prach_seq(int u, cplx *prach_seq)
{
    //e^-j*pi*u*i*(i+1)/N

    double phase;

    for(int i=0; i<L_RA;i++){

        phase = -1*PI_VAL * u * i * (i+1)/L_RA;

        prach_seq[i].re = cos(phase);
        prach_seq[i].im  = sin(phase);
    }

    return;
}

//Correlation function
void *correlation(void *inpParam){

    corr_struct *corrParm = (corr_struct *) inpParam;

    cplx *inp_seq = corrParm->inp_seq;
    double *corr_out_pwr = corrParm->corr_out_pwr;
    int u = corrParm->u ;
    int corr_len = corrParm->corr_len;

    //local replica generation
    cplx *local_replica_seq = malloc(L_RA * sizeof(cplx));
    gen_prach_seq(u, local_replica_seq);

    //correlation out = (ac+bd)+j(bc-ad)
    cplx *out = malloc(L_RA * sizeof(cplx));

    for(int i=0; i<corr_len; i++){

        out[i].re = inp_seq[i].re * local_replica_seq[i].re + inp_seq[i].im * local_replica_seq[i].im;
        out[i].im = inp_seq[i].im * local_replica_seq[i].re - inp_seq[i].re *local_replica_seq[i].im;

        //correlation out power
        corr_out_pwr[i] = out[i].re * out[i].re + out[i].im * out[i].im;

    }

    free(local_replica_seq);
    free(out);

    return NULL;

}


int main(){

    //Prach Parameters
    int u=1, u1=1, u2=7, u3=13;

    // correlation_out power buffer
    double *corr_out_pwr1 = malloc(L_RA * sizeof(double));
    double *corr_out_pwr2 = malloc(L_RA * sizeof(double));
    double *corr_out_pwr3 = malloc(L_RA * sizeof(double));

    //generate input seq which needs to be correlated with different local replica sequences
    cplx *inp_seq = malloc(L_RA * sizeof(cplx));

    gen_prach_seq(u, inp_seq);

    pthread_t thread1, thread2;

    corr_struct thread1_parm = {.corr_len = L_RA, .u=u1};
    thread1_parm.corr_out_pwr = corr_out_pwr1;
    thread1_parm.inp_seq = inp_seq;

    corr_struct thread2_parm = {.corr_len = L_RA, .u=u2};
    thread2_parm.corr_out_pwr = corr_out_pwr2;
    thread2_parm.inp_seq = inp_seq;


    pthread_create(&thread1, NULL, correlation,&thread1_parm);
    pthread_create(&thread2, NULL, correlation,&thread2_parm);


    //perform correlation for 3rd sequence
    corr_struct main_thread_parm = {.corr_len = L_RA, .u=u3};
    main_thread_parm.corr_out_pwr = corr_out_pwr3;
    main_thread_parm.inp_seq = inp_seq;

    correlation(&main_thread_parm);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // correlation out filedump
    char filename[100];
    sprintf(filename,"correlation_out_pwr.txt");
    FILE *file_ptr = fopen(filename, "w");

    if(file_ptr==NULL){

        printf("Error in file opening\n");
        return -1;
    }

    for(int i =0; i<L_RA;i++){
        
        fprintf(file_ptr,"%f\t%f\t%f\n",corr_out_pwr1[i], corr_out_pwr2[i],corr_out_pwr3[i]);

    }

    fclose(file_ptr);

    free(corr_out_pwr1);
    free(corr_out_pwr2);
    free(corr_out_pwr3);

    return 0;
}