#include<stdio.h>
#include<stdlib.h>

/*Implement PRACH preamble detection using cross-correlation.
 
Given:
- received_signal: Complex float array of received time-domain samples
  Format: [sample0_real, sample0_imag, sample1_real, sample1_imag, ...]
  Size: num_samples * 2 (interleaved real/imag)
- preamble_sequence: Complex float array of known preamble sequence
  Format: same as received_signal
  Size: preamble_length * 2
- num_samples: Number of received samples
- preamble_length: Length of preamble sequence
- detection_threshold: Correlation threshold for detection
 
Output:
- detected_offset: Time offset where preamble is detected (-1 if not detected)
- correlation_peak: Peak correlation value
 
Function signature:
int detect_preamble(float* received_signal,
                    float* preamble_sequence,
                    int num_samples,
                    int preamble_length,
                    float detection_threshold,
                    float* correlation_peak);
 
Returns: detected_offset (sample index) or -1 if not detected*/

//(a+ib)(c-id) = ac-iad+ibc+bd = (ac+bd)+i(bc-ad)
//sign of imag of local replica


int detect_preamble(float* received_signal,
                    float* preamble_sequence,
                    int num_samples,
                    int preamble_length,
                    float detection_threshold,
                    float* correlation_peak){

    double *corr_out, *corr_pwr;

    corr_out = malloc(2*num_samples*sizeof(double));

    //correlation
    for(int i=0;i<(2*num_samples);i +=2){

        corr_out[i]  = (received_signal[i]*preamble_sequence[i]) + (received_signal[i+1]*preamble_sequence[i+1]);
        corr_out[i+1] = (received_signal[i+1]*preamble_sequence[i]) - (received_signal[i]*preamble_sequence[i+1]);

    }

    //correlation power computation
    corr_pwr = malloc(num_samples*sizeof(double));

    for(int i=0;i<num_samples;i++){

        corr_pwr[i]  = (corr_out[2*i]*corr_out[2*i])+ (corr_out[(2*i)+1]*corr_out[(2*i)+1]);

    }


}

int main(){






    return 0;
}


