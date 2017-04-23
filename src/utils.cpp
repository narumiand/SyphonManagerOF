//
//  utils.cpp
//  CioDor_in_joule
//
//  Created by Narumi on 2016/07/08.
//
//


#include "utils.hpp"

#define STRINGIFY(A) #A

visual::visual(){
    
    left = new float[BUFFER_SIZE];
    right = new float[BUFFER_SIZE];
    for(int j=0; j < BUFFER_SIZE; j++) {
        left[j] = 0;
        right[j] = 0;
    }
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
}
void visual::call(){
    
}

void visual::setup(){
    
}

void visual::update(){
    t = ofGetElapsedTimef();
}

void visual::draw(){
    
}

void visual::mouseMoved(int x, int y){
    mouseX = x;
    mouseY = y;
}

void visual::audioIn(float *lefti, float *righti,float peaki, int bufferSize){
    left = lefti;
    right = righti;
    peak = peaki;
    bufSize = bufferSize;
}

void visual::windowResized(int x, int y){
    fbo.clear();
    fbo.allocate(x, y);
}

////////////
//Switcher//
////////////

void switcher::keyPressed(int key){
    switch(key){
        case'q': buttons[0].pressedTime = ofGetElapsedTimef();buttons[0].bPressing = true;break;
        case'w': buttons[1].pressedTime = ofGetElapsedTimef();buttons[1].bPressing = true;break;
        case'e': buttons[2].pressedTime = ofGetElapsedTimef();buttons[2].bPressing = true;break;
        case'r': buttons[3].pressedTime = ofGetElapsedTimef();buttons[3].bPressing = true;break;
        case't': buttons[4].pressedTime = ofGetElapsedTimef();buttons[4].bPressing = true;break;
        case'y': buttons[5].pressedTime = ofGetElapsedTimef();buttons[5].bPressing = true;break;
        case'u': buttons[6].pressedTime = ofGetElapsedTimef();buttons[6].bPressing = true;break;
        case'i': buttons[7].pressedTime = ofGetElapsedTimef();buttons[7].bPressing = true;break;
        case'o': buttons[8].pressedTime = ofGetElapsedTimef();buttons[8].bPressing = true;break;
        case'p': buttons[9].pressedTime = ofGetElapsedTimef();buttons[9].bPressing = true;break;
        case'a': buttons[10].pressedTime = ofGetElapsedTimef();buttons[10].bPressing = true;break;
        case's': buttons[11].pressedTime = ofGetElapsedTimef();buttons[11].bPressing = true;break;
        case'd': buttons[12].pressedTime = ofGetElapsedTimef();buttons[12].bPressing = true;break;
        case'f': buttons[13].pressedTime = ofGetElapsedTimef();buttons[13].bPressing = true;break;
        case'g': buttons[14].pressedTime = ofGetElapsedTimef();buttons[14].bPressing = true;break;
        case'h': buttons[15].pressedTime = ofGetElapsedTimef();buttons[15].bPressing = true;break;
        case'j': buttons[16].pressedTime = ofGetElapsedTimef();buttons[16].bPressing = true;break;
        case'k': buttons[17].pressedTime = ofGetElapsedTimef();buttons[17].bPressing = true;break;
        case'l': buttons[18].pressedTime = ofGetElapsedTimef();buttons[18].bPressing = true;break;
        case'z': buttons[19].pressedTime = ofGetElapsedTimef();buttons[19].bPressing = true;break;
        case'x': buttons[20].pressedTime = ofGetElapsedTimef();buttons[20].bPressing = true;break;
        case'c': buttons[21].pressedTime = ofGetElapsedTimef();buttons[21].bPressing = true;break;
        case'v': buttons[22].pressedTime = ofGetElapsedTimef();buttons[22].bPressing = true;break;
        case'b': buttons[23].pressedTime = ofGetElapsedTimef();buttons[23].bPressing = true;break;
        case'n': buttons[24].pressedTime = ofGetElapsedTimef();buttons[24].bPressing = true;break;
        case'm': buttons[25].pressedTime = ofGetElapsedTimef();buttons[25].bPressing = true;break;
        default:break;
            
    }
    float lastTime = 0.0;
    for(int i = 0; i < 26 ; i++){
        if(lastTime >= buttons[i].pressedTime){
            lastTime = lastTime;
        }else{
            lastTime = buttons[i].pressedTime;
            sourceIdx = i;
        }
    }
}
void switcher::keyReleased(int key){
    switch(key){
        case'q': buttons[0].pressedTime = 0.0;buttons[0].bPressing = false;break;
        case'w': buttons[1].pressedTime = 0.0;buttons[1].bPressing = false;break;
        case'e': buttons[2].pressedTime = 0.0;buttons[2].bPressing = false;break;
        case'r': buttons[3].pressedTime = 0.0;buttons[3].bPressing = false;break;
        case't': buttons[4].pressedTime = 0.0;buttons[4].bPressing = false;break;
        case'y': buttons[5].pressedTime = 0.0;buttons[5].bPressing = false;break;
        case'u': buttons[6].pressedTime = 0.0;buttons[6].bPressing = false;break;
        case'i': buttons[7].pressedTime = 0.0;buttons[7].bPressing = false;break;
        case'o': buttons[8].pressedTime = 0.0;buttons[8].bPressing = false;break;
        case'p': buttons[9].pressedTime = 0.0;buttons[9].bPressing = false;break;
        case'a': buttons[10].pressedTime = 0.0;buttons[10].bPressing = false;break;
        case's': buttons[11].pressedTime = 0.0;buttons[11].bPressing = false;break;
        case'd': buttons[12].pressedTime = 0.0;buttons[12].bPressing = false;break;
        case'f': buttons[13].pressedTime = 0.0;buttons[13].bPressing = false;break;
        case'g': buttons[14].pressedTime = 0.0;buttons[14].bPressing = false;break;
        case'h': buttons[15].pressedTime = 0.0;buttons[15].bPressing = false;break;
        case'j': buttons[16].pressedTime = 0.0;buttons[16].bPressing = false;break;
        case'k': buttons[17].pressedTime = 0.0;buttons[17].bPressing = false;break;
        case'l': buttons[18].pressedTime = 0.0;buttons[18].bPressing = false;break;
        case'z': buttons[19].pressedTime = 0.0;buttons[19].bPressing = false;break;
        case'x': buttons[20].pressedTime = 0.0;buttons[20].bPressing = false;break;
        case'c': buttons[21].pressedTime = 0.0;buttons[21].bPressing = false;break;
        case'v': buttons[22].pressedTime = 0.0;buttons[22].bPressing = false;break;
        case'b': buttons[23].pressedTime = 0.0;buttons[23].bPressing = false;break;
        case'n': buttons[24].pressedTime = 0.0;buttons[24].bPressing = false;break;
        case'm': buttons[25].pressedTime = 0.0;buttons[25].bPressing = false;break;
        default:break;
            
    }
    
    float lastTime = 0.0;
    for(int i = 0; i < 26 ; i++){
        if(lastTime >= buttons[i].pressedTime){
            lastTime = lastTime;
        }else{
            lastTime = buttons[i].pressedTime;
            sourceIdx = i;
        }
    }
    
}


//////////////////
//randomInterval//
//////////////////

void randomInterval::setup(float min , float max){
    minTime = min;
    maxTime = max;
    interval = ofRandom(minTime,maxTime);
    t = ofGetElapsedTimef();
    sTime = t;
    count = 0;
    
}

bool randomInterval::update(){
    t = ofGetElapsedTimef();
    
    eTime = t - sTime;
    
    if(eTime >= interval){
        interval = ofRandom(minTime,maxTime);
        sTime = t;
        count++;
        return true;
    }
    
    
    return false;
}

void randomInterval::setInterval(float min , float max){
    minTime = min;
    maxTime = max;
}

float randomInterval::getInterval(){
    return interval;
}

int randomInterval::getCount(){
    return count;
}


ofVec3f transform3D(ofVec3f pos,ofVec3f rot,ofVec3f center,ofVec3f trans,ofVec3f scale){
    ofVec3f result;
    
    result = pos - center;
    
    //rotX
    ofVec3f tmp = result;
    result.x = tmp.x;
    result.y = tmp.y * cos(rot.x) + tmp.z * (-sin(rot.x));
    result.z = tmp.y * sin(rot.x) + tmp.z * cos(rot.x);
    
    //rotY
    tmp = result;
    result.x = tmp.x * cos(rot.y) + tmp.z * sin(rot.y);
    result.y = tmp.y;
    result.z = tmp.x * (-sin(rot.y)) + tmp.z * cos(rot.y);
    
    //rotZ
    tmp = result;
    result.x = (tmp.x * cos(rot.z) + tmp.y * (-sin(rot.z))) * scale.x;
    result.y = (tmp.x * sin(rot.z) + tmp.y * cos(rot.z)) * scale.y;
    result.z = tmp.z * scale.z;
    
    result += center;
    
    result += trans;
    
    return result;
    
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

///////
//fft//
///////

int **gFFTBitTable = NULL;
const int MaxFastBits = 16;

int IsPowerOfTwo(int x)
{
    if (x < 2)
        return false;
    
    if (x & (x - 1))             /* Thanks to 'byang' for this cute trick! */
        return false;
    
    return true;
}

int NumberOfBitsNeeded(int PowerOfTwo)
{
    int i;
    
    if (PowerOfTwo < 2) {
        fprintf(stderr, "Error: FFT called with size %d\n", PowerOfTwo);
        exit(1);
    }
    
    for (i = 0;; i++)
        if (PowerOfTwo & (1 << i))
            return i;
}

int ReverseBits(int index, int NumBits)
{
    int i, rev;
    
    for (i = rev = 0; i < NumBits; i++) {
        rev = (rev << 1) | (index & 1);
        index >>= 1;
    }
    
    return rev;
}

void InitFFT()
{
    gFFTBitTable = new int *[MaxFastBits];
    
    int len = 2;
    for (int b = 1; b <= MaxFastBits; b++) {
        
        gFFTBitTable[b - 1] = new int[len];
        
        for (int i = 0; i < len; i++)
            gFFTBitTable[b - 1][i] = ReverseBits(i, b);
        
        len <<= 1;
    }
}

inline int FastReverseBits(int i, int NumBits)
{
    if (NumBits <= MaxFastBits)
        return gFFTBitTable[NumBits - 1][i];
    else
        return ReverseBits(i, NumBits);
}

/*
 * Complex Fast Fourier Transform
 */

void FFT(int NumSamples,
         bool InverseTransform,
         float *RealIn, float *ImagIn, float *RealOut, float *ImagOut)
{
    int NumBits;                 /* Number of bits needed to store indices */
    int i, j, k, n;
    int BlockSize, BlockEnd;
    
    double angle_numerator = 2.0 * M_PI;
    float tr, ti;                /* temp real, temp imaginary */
    
    if (!IsPowerOfTwo(NumSamples)) {
        fprintf(stderr, "%d is not a power of two\n", NumSamples);
        exit(1);
    }
    
    if (!gFFTBitTable)
        InitFFT();
    
    if (InverseTransform)
        angle_numerator = -angle_numerator;
    
    NumBits = NumberOfBitsNeeded(NumSamples);
    
    /*
     **   Do simultaneous data copy and bit-reversal ordering into outputs...
     */
    
    for (i = 0; i < NumSamples; i++) {
        j = FastReverseBits(i, NumBits);
        RealOut[j] = RealIn[i];
        ImagOut[j] = (ImagIn == NULL) ? 0.0 : ImagIn[i];
    }
    
    /*
     **   Do the FFT itself...
     */
    
    BlockEnd = 1;
    for (BlockSize = 2; BlockSize <= NumSamples; BlockSize <<= 1) {
        
        double delta_angle = angle_numerator / (double) BlockSize;
        
        float sm2 = sin(-2 * delta_angle);
        float sm1 = sin(-delta_angle);
        float cm2 = cos(-2 * delta_angle);
        float cm1 = cos(-delta_angle);
        float w = 2 * cm1;
        float ar0, ar1, ar2, ai0, ai1, ai2;
        
        for (i = 0; i < NumSamples; i += BlockSize) {
            ar2 = cm2;
            ar1 = cm1;
            
            ai2 = sm2;
            ai1 = sm1;
            
            for (j = i, n = 0; n < BlockEnd; j++, n++) {
                ar0 = w * ar1 - ar2;
                ar2 = ar1;
                ar1 = ar0;
                
                ai0 = w * ai1 - ai2;
                ai2 = ai1;
                ai1 = ai0;
                
                k = j + BlockEnd;
                tr = ar0 * RealOut[k] - ai0 * ImagOut[k];
                ti = ar0 * ImagOut[k] + ai0 * RealOut[k];
                
                RealOut[k] = RealOut[j] - tr;
                ImagOut[k] = ImagOut[j] - ti;
                
                RealOut[j] += tr;
                ImagOut[j] += ti;
            }
        }
        
        BlockEnd = BlockSize;
    }
    
    /*
     **   Need to normalize if inverse transform...
     */
    
    if (InverseTransform) {
        float denom = (float) NumSamples;
        
        for (i = 0; i < NumSamples; i++) {
            RealOut[i] /= denom;
            ImagOut[i] /= denom;
        }
    }
}

/*
 * Real Fast Fourier Transform
 *
 * This function was based on the code in Numerical Recipes in C.
 * In Num. Rec., the inner loop is based on a single 1-based array
 * of interleaved real and imaginary numbers.  Because we have two
 * separate zero-based arrays, our indices are quite different.
 * Here is the correspondence between Num. Rec. indices and our indices:
 *
 * i1  <->  real[i]
 * i2  <->  imag[i]
 * i3  <->  real[n/2-i]
 * i4  <->  imag[n/2-i]
 */

void RealFFT(int NumSamples, float *RealIn, float *RealOut, float *ImagOut)
{
    int Half = NumSamples / 2;
    int i;
    
    float theta = M_PI / Half;
    
    float *tmpReal = new float[Half];
    float *tmpImag = new float[Half];
    
    for (i = 0; i < Half; i++) {
        tmpReal[i] = RealIn[2 * i];
        tmpImag[i] = RealIn[2 * i + 1];
    }
    
    FFT(Half, 0, tmpReal, tmpImag, RealOut, ImagOut);
    
    float wtemp = float (sin(0.5 * theta));
    
    float wpr = -2.0 * wtemp * wtemp;
    float wpi = float (sin(theta));
    float wr = 1.0 + wpr;
    float wi = wpi;
    
    int i3;
    
    float h1r, h1i, h2r, h2i;
    
    for (i = 1; i < Half / 2; i++) {
        
        i3 = Half - i;
        
        h1r = 0.5 * (RealOut[i] + RealOut[i3]);
        h1i = 0.5 * (ImagOut[i] - ImagOut[i3]);
        h2r = 0.5 * (ImagOut[i] + ImagOut[i3]);
        h2i = -0.5 * (RealOut[i] - RealOut[i3]);
        
        RealOut[i] = h1r + wr * h2r - wi * h2i;
        ImagOut[i] = h1i + wr * h2i + wi * h2r;
        RealOut[i3] = h1r - wr * h2r + wi * h2i;
        ImagOut[i3] = -h1i + wr * h2i + wi * h2r;
        
        wr = (wtemp = wr) * wpr - wi * wpi + wr;
        wi = wi * wpr + wtemp * wpi + wi;
    }
    
    RealOut[0] = (h1r = RealOut[0]) + ImagOut[0];
    ImagOut[0] = h1r - ImagOut[0];
    
    delete[]tmpReal;
    delete[]tmpImag;
}

/*
 * PowerSpectrum
 *
 * This function computes the same as RealFFT, above, but
 * adds the squares of the real and imaginary part of each
 * coefficient, extracting the power and throwing away the
 * phase.
 *
 * For speed, it does not call RealFFT, but duplicates some
 * of its code.
 */

void PowerSpectrum(int NumSamples, float *In, float *Out)
{
    int Half = NumSamples / 2;
    int i;
    
    float theta = M_PI / Half;
    
    float *tmpReal = new float[Half];
    float *tmpImag = new float[Half];
    float *RealOut = new float[Half];
    float *ImagOut = new float[Half];
    
    for (i = 0; i < Half; i++) {
        tmpReal[i] = In[2 * i];
        tmpImag[i] = In[2 * i + 1];
    }
    
    FFT(Half, 0, tmpReal, tmpImag, RealOut, ImagOut);
    
    float wtemp = float (sin(0.5 * theta));
    
    float wpr = -2.0 * wtemp * wtemp;
    float wpi = float (sin(theta));
    float wr = 1.0 + wpr;
    float wi = wpi;
    
    int i3;
    
    float h1r, h1i, h2r, h2i, rt, it;
    //float total=0;
    
    for (i = 1; i < Half / 2; i++) {
        
        i3 = Half - i;
        
        h1r = 0.5 * (RealOut[i] + RealOut[i3]);
        h1i = 0.5 * (ImagOut[i] - ImagOut[i3]);
        h2r = 0.5 * (ImagOut[i] + ImagOut[i3]);
        h2i = -0.5 * (RealOut[i] - RealOut[i3]);
        
        rt = h1r + wr * h2r - wi * h2i; //printf("Realout%i = %f",i,rt);total+=fabs(rt);
        it = h1i + wr * h2i + wi * h2r; // printf("  Imageout%i = %f\n",i,it);
        
        Out[i] = rt * rt + it * it;
        
        rt = h1r - wr * h2r + wi * h2i;
        it = -h1i + wr * h2i + wi * h2r;
        
        Out[i3] = rt * rt + it * it;
        
        wr = (wtemp = wr) * wpr - wi * wpi + wr;
        wi = wi * wpr + wtemp * wpi + wi;
    }
    //printf("total = %f\n",total);
    rt = (h1r = RealOut[0]) + ImagOut[0];
    it = h1r - ImagOut[0];
    Out[0] = rt * rt + it * it;
    
    rt = RealOut[Half / 2];
    it = ImagOut[Half / 2];
    Out[Half / 2] = rt * rt + it * it;
    
    delete[]tmpReal;
    delete[]tmpImag;
    delete[]RealOut;
    delete[]ImagOut;
}

/*
 * Windowing Functions
 */

int NumWindowFuncs()
{
    return 4;
}

char *WindowFuncName(int whichFunction)
{
    switch (whichFunction) {
        default:
        case 0:
            return "Rectangular";
        case 1:
            return "Bartlett";
        case 2:
            return "Hamming";
        case 3:
            return "Hanning";
    }
}

void WindowFunc(int whichFunction, int NumSamples, float *in)
{
    int i;
    
    if (whichFunction == 1) {
        // Bartlett (triangular) window
        for (i = 0; i < NumSamples / 2; i++) {
            in[i] *= (i / (float) (NumSamples / 2));
            in[i + (NumSamples / 2)] *=
            (1.0 - (i / (float) (NumSamples / 2)));
        }
    }
    
    if (whichFunction == 2) {
        // Hamming
        for (i = 0; i < NumSamples; i++)
            in[i] *= 0.54 - 0.46 * cos(2 * M_PI * i / (NumSamples - 1));
    }
    
    if (whichFunction == 3) {
        // Hanning
        for (i = 0; i < NumSamples; i++)
            in[i] *= 0.50 - 0.50 * cos(2 * M_PI * i / (NumSamples - 1));
    }
}

/* constructor */
fft::fft() {
    
    
}

/* destructor */
fft::~fft() {
    
    
}

/* Calculate the power spectrum */
void fft::powerSpectrum(int start, int half, float *data, int windowSize,float *magnitude,float *phase, float *power, float *avg_power) {
    int i;
    int windowFunc = 3;
    float total_power = 0.0f;
    
    /* processing variables*/
    float *in_real = new float[windowSize];
    float *in_img = new float[windowSize];
    float *out_real = new float[windowSize];
    float *out_img = new float[windowSize];
    
    for (i = 0; i < windowSize; i++) {
        in_real[i] = data[start + i];
    }
    
    WindowFunc(windowFunc, windowSize, in_real);
    RealFFT(windowSize, in_real, out_real, out_img);
    
    for (i = 0; i < half; i++) {
        /* compute power */
        power[i] = out_real[i]*out_real[i] + out_img[i]*out_img[i];
        total_power += power[i];
        /* compute magnitude and phase */
        magnitude[i] = 2.0*sqrt(power[i]);
        phase[i] = atan2(out_img[i],out_real[i]);
    }
    /* calculate average power */
    *(avg_power) = total_power / (float) half;
				
    delete[]in_real;
    delete[]in_img;
    delete[]out_real;
    delete[]out_img;
}

void fft::inversePowerSpectrum(int start, int half, int windowSize, float *finalOut,float *magnitude,float *phase) {
    int i;
    int windowFunc = 3;
    
    /* processing variables*/
    float *in_real = new float[windowSize];
    float *in_img = new float[windowSize];
    float *out_real = new float[windowSize];
    float *out_img = new float[windowSize];
    
    /* get real and imag part */
    for (i = 0; i < half; i++) {	
        in_real[i] = magnitude[i]*cos(phase[i]);
        in_img[i]  = magnitude[i]*sin(phase[i]);
    }
    
    /* zero negative frequencies */
    for (i = half; i < windowSize; i++) {	
        in_real[i] = 0.0;
        in_img[i] = 0.0;
    }
    
    FFT(windowSize, 1, in_real, in_img, out_real, out_img); // second parameter indicates inverse transform
    WindowFunc(windowFunc, windowSize, out_real);
				
    for (i = 0; i < windowSize; i++) {
        finalOut[start + i] += out_real[i];
    }
    
    delete[]in_real;
    delete[]in_img;   
    delete[]out_real;
    delete[]out_img;
}


////////////////
//BeatDetektor//
////////////////

void BeatDetektor::process(float timer_seconds, std::vector<float> &fft_data)
{
    if (!last_timer) { last_timer = timer_seconds; return; }	// ignore 0 start time
    
    if (timer_seconds < last_timer) { reset(); return; }
    
    float timestamp = timer_seconds;
    
    last_update = timer_seconds - last_timer;
    last_timer = timer_seconds;
    
    total_time+=last_update;
    
    unsigned int range_step = (fft_data.size()/BD_DETECTION_RANGES);
    unsigned int range = 0;
    int i,x;
    float v;
    
    float bpm_floor = 60.0/BPM_MAX;
    float bpm_ceil = 60.0/BPM_MIN;
    
    if (current_bpm != current_bpm) current_bpm = 0;
    
    for (x=0; x<fft_data.size(); x+=range_step)
    {
        if (!src)
        {
            a_freq_range[range] = 0;
            
            // accumulate frequency values for this range
            for (i = x; i<x+range_step; i++)
            {
                v = fabs(fft_data[i]);
                a_freq_range[range] += v;
            }
            
            // average for range
            a_freq_range[range] /= range_step;
            
            // two sets of averages chase this one at a
            
            // moving average, increment closer to a_freq_range at a rate of 1.0 / detection_rate seconds
            ma_freq_range[range] -= (ma_freq_range[range]-a_freq_range[range])*last_update*detection_rate;
            // moving average of moving average, increment closer to ma_freq_range at a rate of 1.0 / detection_rate seconds
            maa_freq_range[range] -= (maa_freq_range[range]-ma_freq_range[range])*last_update*detection_rate;
        }
        else
        {
            a_freq_range[range] = src->a_freq_range[range];
            ma_freq_range[range] = src->ma_freq_range[range];
            maa_freq_range[range] = src->maa_freq_range[range];
        }
        
        
        // if closest moving average peaks above trailing (with a tolerance of BD_DETECTION_FACTOR) then trigger a detection for this range
        bool det = (ma_freq_range[range]*detection_factor >= maa_freq_range[range]);
        
        // compute bpm clamps for comparison to gap lengths
        
        // clamp detection averages to input ranges
        if (ma_bpm_range[range] > bpm_ceil) ma_bpm_range[range] = bpm_ceil;
        if (ma_bpm_range[range] < bpm_floor) ma_bpm_range[range] = bpm_floor;
        if (maa_bpm_range[range] > bpm_ceil) maa_bpm_range[range] = bpm_ceil;
        if (maa_bpm_range[range] < bpm_floor) maa_bpm_range[range] = bpm_floor;
        
        bool rewarded = false;
        
        // new detection since last, test it's quality
        if (!detection[range] && det)
        {
            // calculate length of gap (since start of last trigger)
            float trigger_gap = timestamp-last_detection[range];
            
#define REWARD_VALS 7
            float reward_tolerances[REWARD_VALS] = { 0.001, 0.005, 0.01, 0.02, 0.04, 0.08, 0.10  };
            float reward_multipliers[REWARD_VALS] = { 20.0, 10.0, 8.0, 1.0, 1.0/2.0, 1.0/4.0, 1.0/8.0 };
            
            // trigger falls within acceptable range,
            if (trigger_gap < bpm_ceil && trigger_gap > (bpm_floor))
            {
                // compute gap and award quality
                
                for (i = 0; i < REWARD_VALS; i++)
                {
                    if (fabs(ma_bpm_range[range]-trigger_gap) < ma_bpm_range[range]*reward_tolerances[i])
                    {
                        detection_quality[range] += quality_reward * reward_multipliers[i];
                        rewarded = true;
#if DEVTEST_BUILD
                        //						printf("1/1\n");
                        contribution_counter[1]++;
#endif
                        
                    }
                }
                
                
                if (rewarded)
                {
                    last_detection[range] = timestamp;
                }
            }
            else if (trigger_gap >= bpm_ceil) // low quality, gap exceeds maximum time
            {
                // test for 2* beat
                trigger_gap /= 2.0;
                // && fabs((60.0/trigger_gap)-(60.0/ma_bpm_range[range])) < 50.0
                if (trigger_gap < bpm_ceil && trigger_gap > (bpm_floor)) for (i = 0; i < REWARD_VALS; i++)
                {
                    if (fabs(ma_bpm_range[range]-trigger_gap) < ma_bpm_range[range]*reward_tolerances[i])
                    {
                        detection_quality[range] += quality_reward * reward_multipliers[i];
                        rewarded = true;
#if DEVTEST_BUILD
                        //						printf("2/1\n");
                        contribution_counter[2]++;
#endif
                    }
                }
                
                if (!rewarded) trigger_gap *= 2.0;
                
                // start a new gap test, next gap is guaranteed to be longer
                last_detection[range] = timestamp;
            }
            
            
            float qmp = (detection_quality[range]/quality_avg)*BD_QUALITY_STEP;
            if (qmp > 1.0)
            {
                qmp = 1.0;
            }
            
            if (rewarded)
            {
                ma_bpm_range[range] -= (ma_bpm_range[range]-trigger_gap) * qmp;
                maa_bpm_range[range] -= (maa_bpm_range[range]-ma_bpm_range[range]) * qmp;
            }
            else if (trigger_gap >= bpm_floor && trigger_gap <= bpm_ceil)
            {
                if (detection_quality[range] < quality_avg*BD_QUALITY_TOLERANCE && current_bpm)
                {
                    ma_bpm_range[range] -= (ma_bpm_range[range]-trigger_gap) * BD_QUALITY_STEP;
                    maa_bpm_range[range] -= (maa_bpm_range[range]-ma_bpm_range[range]) * BD_QUALITY_STEP;
                }
                detection_quality[range] -= BD_QUALITY_STEP;
            }
            else if (trigger_gap >= bpm_ceil)
            {
                if (detection_quality[range] < quality_avg*BD_QUALITY_TOLERANCE && current_bpm)
                {
                    ma_bpm_range[range] -= (ma_bpm_range[range]-current_bpm) * 0.5;
                    maa_bpm_range[range] -= (maa_bpm_range[range]-ma_bpm_range[range]) * 0.5;
                }
                detection_quality[range] -= quality_reward*BD_QUALITY_STEP;
            }
            
        }
        
        if ((!rewarded && timestamp-last_detection[range] > bpm_ceil) || ((det && fabs(ma_bpm_range[range]-current_bpm) > bpm_offset)))
            detection_quality[range] -= detection_quality[range]*BD_QUALITY_STEP*quality_decay*last_update;
        
        // quality bottomed out, set to 0
        if (detection_quality[range] <= 0) detection_quality[range]=0.001;
        
        
        detection[range] = det;
        
        range++;
    }
    
    
    // total contribution weight
    quality_total = 0;
    
    // total of bpm values
    float bpm_total = 0;
    // number of bpm ranges that contributed to this test
    int bpm_contributions = 0;
    
    
    // accumulate quality weight total
    for (x=0; x<BD_DETECTION_RANGES; x++)
    {
        quality_total += detection_quality[x];
    }
    
    // determine the average weight of each quality range
    quality_avg = quality_total / (float)BD_DETECTION_RANGES;
    
    
    ma_quality_avg += (quality_avg - ma_quality_avg) * last_update * detection_rate/2.0;
    maa_quality_avg += (ma_quality_avg - maa_quality_avg) * last_update;
    ma_quality_total += (quality_total - ma_quality_total) * last_update * detection_rate/2.0;
    
    ma_quality_avg -= 0.98*ma_quality_avg*last_update*3.0;
    
    if (ma_quality_total <= 0) ma_quality_total = 1.0;
    if (ma_quality_avg <= 0) ma_quality_avg = 1.0;
    
    float avg_bpm_offset = 0.0;
    float offset_test_bpm = current_bpm;
    std::map<int,float> draft;
    std::map<int,float> fract_draft;
    
    {
        for (x=0; x<BD_DETECTION_RANGES; x++)
        {
            // if this detection range weight*tolerance is higher than the average weight then add it's moving average contribution
            if (detection_quality[x]*BD_QUALITY_TOLERANCE >= ma_quality_avg)
            {
                if (maa_bpm_range[x] < bpm_ceil && maa_bpm_range[x] > bpm_floor)
                {
                    bpm_total += maa_bpm_range[x];
                    
                    float draft_float = round((60.0/maa_bpm_range[x])*1000.0);
                    
                    draft_float = (fabs(ceil(draft_float)-(60.0/current_bpm)*1000.0)<(fabs(floor(draft_float)-(60.0/current_bpm)*1000.0)))?ceil(draft_float/10.0):floor(draft_float/10.0);
                    
                    float draft_int = (int)(draft_float/10.0);
                    
                    draft[draft_int]+= (detection_quality[x]/quality_avg);
                    bpm_contributions++;
                    if (offset_test_bpm == 0.0) offset_test_bpm = maa_bpm_range[x];
                    else
                    {
                        avg_bpm_offset += fabs(offset_test_bpm-maa_bpm_range[x]);
                    }
                    
                }
            }
        }
    }
    
    // if we have one or more contributions that pass criteria then attempt to display a guess
    bool has_prediction = (bpm_contributions>=minimum_contributions)?true:false;
    
    
    std::map<int,float>::iterator draft_i;
    
    if (has_prediction)
    {
        
        int draft_winner=0;
        int win_max = 0;
        
        for (draft_i = draft.begin(); draft_i != draft.end(); draft_i++)
        {
            if ((*draft_i).second > win_max)
            {
                win_max = (*draft_i).second;
                draft_winner = (*draft_i).first;
            }
        }
        
        bpm_predict = (60.0/(float)(draft_winner/10.0));
        
        avg_bpm_offset /= (float)bpm_contributions;
        bpm_offset = avg_bpm_offset;
        
        if (!current_bpm)
        {
            current_bpm = bpm_predict;
        }
        
        
        if (current_bpm && bpm_predict) current_bpm -= (current_bpm-bpm_predict)*last_update; //*avg_bpm_offset*200.0;
        if (current_bpm != current_bpm || current_bpm < 0) current_bpm = 0;
        
        
        // hold a contest for bpm to find the current mode
        std::map<int,float>::iterator contest_i;
        
        float contest_max=0;
        
        for (contest_i = bpm_contest.begin(); contest_i != bpm_contest.end(); contest_i++)
        {
            if (contest_max < (*contest_i).second) contest_max =(*contest_i).second;
            if (((*contest_i).second) > BD_FINISH_LINE/2.0)
            {
                bpm_contest_lo[round((float)((*contest_i).first)/10.0)]+= (((*contest_i).second)/10.0)*last_update;
            }
        }
        
        
        // normalize to a finish line of BD_FINISH_LINE
        if (contest_max > finish_line)
        {
            for (contest_i = bpm_contest.begin(); contest_i != bpm_contest.end(); contest_i++)
            {
                (*contest_i).second=((*contest_i).second/contest_max)*finish_line;
            }
        }
        
        contest_max = 0;
        
        for (contest_i = bpm_contest_lo.begin(); contest_i != bpm_contest_lo.end(); contest_i++)
        {
            if (contest_max < (*contest_i).second) contest_max =(*contest_i).second;
        }
        
        if (contest_max > finish_line)
        {
            for (contest_i = bpm_contest_lo.begin(); contest_i != bpm_contest_lo.end(); contest_i++)
            {
                (*contest_i).second=((*contest_i).second/contest_max)*finish_line;
            }
        }
        
        
        // decay contest values from last loop
        for (contest_i = bpm_contest.begin(); contest_i != bpm_contest.end(); contest_i++)
        {
            (*contest_i).second-=(*contest_i).second*(last_update/detection_rate);
        }
        
        // decay contest values from last loop
        for (contest_i = bpm_contest_lo.begin(); contest_i != bpm_contest_lo.end(); contest_i++)
        {
            (*contest_i).second-=(*contest_i).second*(last_update/detection_rate);
        }
        
        
        bpm_timer+=last_update;
        
        int winner = 0;
        int winner_lo = 0;				
        
        // attempt to display the beat at the beat interval ;)
        if (bpm_timer > winning_bpm/4.0 && current_bpm)
        {		
            if (winning_bpm) while (bpm_timer > winning_bpm/4.0) bpm_timer -= winning_bpm/4.0;
            
            // increment beat counter
            
            quarter_counter++;		
            half_counter= quarter_counter/2;
            beat_counter = quarter_counter/4;
            
            // award the winner of this iteration
            bpm_contest[(int)round((60.0/current_bpm)*10.0)]+=quality_reward;
            
            win_val = 0;
            
            // find the overall winner so far
            for (contest_i = bpm_contest.begin(); contest_i != bpm_contest.end(); contest_i++)
            {
                if (win_val < (*contest_i).second)
                {
                    winner = (*contest_i).first;
                    win_val = (*contest_i).second;
                }
            }
            
            if (winner)
            {
                win_bpm_int = winner;
                winning_bpm = 60.0/(float)(winner/10.0);
            }
            
            
            win_val_lo = 0;		
            
            // find the overall winner so far
            for (contest_i = bpm_contest_lo.begin(); contest_i != bpm_contest_lo.end(); contest_i++)
            {
                if (win_val_lo < (*contest_i).second)
                {
                    winner_lo = (*contest_i).first;
                    win_val_lo = (*contest_i).second;
                }
            }
            
            if (winner_lo)
            {
                win_bpm_int_lo = winner_lo;
                winning_bpm_lo = 60.0/(float)(winner_lo);
            }
#if DEVTEST_BUILD
            if (debugmode && ((quarter_counter % 4) == 0)) 
            {
                printf("[%0.0f-%0.0f] quality: %0.2f / %0.2f percent",BPM_MIN,BPM_MAX,quality_total,(quality_total/(ma_quality_avg*(float)BD_DETECTION_RANGES))*50.0);
                printf(", current bpm estimate: %d @ %0.2f / %0.5f",winner,win_val,bpm_offset);
                printf("  low res estimate: %d @ %0.2f\n",winner_lo,win_val_lo);
                std::map<int, int>::iterator contrib_i;
                
                printf("contrib: ");
                for (contrib_i = contribution_counter.begin(); contrib_i !=  contribution_counter.end(); contrib_i++)
                {
                    printf("%d: %d \t",(*contrib_i).first,(*contrib_i).second);
                }
                printf("\n");
            }
#endif
        }
    }
}


