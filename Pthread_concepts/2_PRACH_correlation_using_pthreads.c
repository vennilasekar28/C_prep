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
    double corr_out_pwr;
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
    double *corr_out_pwr = &corrParm->corr_out_pwr;
    int u = corrParm->u ;
    int corr_len = corrParm->corr_len;

    //local replica generation
    cplx *local_replica_seq = malloc(L_RA * sizeof(cplx));
    gen_prach_seq(u, local_replica_seq);

    //correlation out = (ac+bd)+j(bc-ad)
    cplx out;

    out.re = 0;
    out.im = 0;

    for(int i=0; i<corr_len; i++){

        out.re += inp_seq[i].re * local_replica_seq[i].re + inp_seq[i].im * local_replica_seq[i].im;
        out.im += inp_seq[i].im * local_replica_seq[i].re - inp_seq[i].re *local_replica_seq[i].im;

    }

    //correlation out power
    *corr_out_pwr = out.re * out.re + out.im * out.im;

    free(local_replica_seq);

    return NULL;

}


int main(){

    //Prach Parameters
    int u=1, u1=1, u2=7, u3=13;

    //generate input seq which needs to be correlated with different local replica sequences
    cplx *inp_seq = malloc(L_RA * sizeof(cplx));

    gen_prach_seq(u, inp_seq);

    pthread_t thread1, thread2;

    corr_struct thread1_parm = {.corr_len = L_RA, .u=u1};
    thread1_parm.corr_out_pwr = 0.0;
    thread1_parm.inp_seq = inp_seq;

    corr_struct thread2_parm = {.corr_len = L_RA, .u=u2};
    thread2_parm.corr_out_pwr = 0.0;
    thread2_parm.inp_seq = inp_seq;


    pthread_create(&thread1, NULL, correlation,&thread1_parm);
    pthread_create(&thread2, NULL, correlation,&thread2_parm);


    //perform correlation for 3rd sequence
    corr_struct main_thread_parm = {.corr_len = L_RA, .u=u3};
    main_thread_parm.corr_out_pwr = 0.0;
    main_thread_parm.inp_seq = inp_seq;

    correlation(&main_thread_parm);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("The correlation output power with u1, u7, u13 are %f\t%f\t%f\n",\
        thread1_parm.corr_out_pwr, thread2_parm.corr_out_pwr,main_thread_parm.corr_out_pwr);

    return 0;
}