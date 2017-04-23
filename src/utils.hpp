//
//  utils.hpp
//  CioDor_in_joule
//
//  Created by Narumi on 2016/07/08.
//
//

#ifndef utils_hpp
#define utils_hpp
#define BUFFER_SIZE 1024
#include <stdio.h>
#include "ofMain.h"
#include <map>
#include <vector>
#include <math.h>
#define BD_DETECTION_RANGES 128
#define BD_DETECTION_RATE 12.0
#define BD_DETECTION_FACTOR 0.925

#define BD_QUALITY_TOLERANCE 0.96
#define BD_QUALITY_DECAY 0.95
#define BD_QUALITY_REWARD 7.0
#define BD_QUALITY_STEP 0.1
#define BD_FINISH_LINE 60.0
#define BD_MINIMUM_CONTRIBUTIONS 6

#define STRINGIFY(A) #A


class visual {
    
public:
    visual();
    virtual void setup();
    virtual void call();
    virtual void update();
    virtual void draw();
    virtual void mouseMoved(int x,int y);
    virtual void audioIn(float *left, float *right,float peaki, int bufferSize);
    virtual void windowResized(int w, int h);
    
    ofVec3f accel = ofVec3f(0,0,0);
    ofVec3f gyro = ofVec3f(0,0,0);
    ofQuaternion quaternion = ofQuaternion(0,0,0,0);
    
    bool enable;
    float startTime;
    float t;
    float endTime;
    float alpha;
    bool bRender;
    int bufSize;
    float *left;
    float *right;
    float peak;
    int mouseX;
    int mouseY;
    ofFbo fbo;
    ofShader shader;
};

class button{
public:
    float pressedTime = 0.0;
    bool bPressing = false;
    
    
};

class switcher{
public:
    void keyPressed(int key);
    void keyReleased(int key);
    int sourceIdx;
    button buttons[26];
    
};


class randomInterval{
public:
    void setup(float min,float max);
    bool update();
    void setInterval(float min,float max);
    float getInterval();
    int getCount();
private:
    int count;
    float minTime;
    float maxTime;
    float eTime;
    float sTime;
    float t;
    float interval;
};

ofVec3f transform3D(ofVec3f pos,ofVec3f rot,ofVec3f center,ofVec3f trans,ofVec3f scale);


///////
//fft//
///////


#ifndef _FFT
#define _FFT

#ifndef M_PI
#define	M_PI		3.14159265358979323846  /* pi */
#endif


class fft {
    
public:
    
    fft();
    ~fft();
    
    /* Calculate the power spectrum */
    void powerSpectrum(int start, int half, float *data, int windowSize,float *magnitude,float *phase, float *power, float *avg_power);
    /* ... the inverse */
    void inversePowerSpectrum(int start, int half, int windowSize, float *finalOut,float *magnitude,float *phase);
    
    
};


#endif	

class BeatDetektor
{
public:
    float BPM_MIN;
    float BPM_MAX;
    
    BeatDetektor *src;
    
    float current_bpm;
    float winning_bpm;
    float winning_bpm_lo;
    float win_val;
    int win_bpm_int;
    float win_val_lo;
    int win_bpm_int_lo;
    
    float bpm_predict;
    
    bool is_erratic;
    float bpm_offset;
    float last_timer;
    float last_update;
    float total_time;
    
    float bpm_timer;
    int beat_counter;
    int half_counter;
    int quarter_counter;
    float detection_factor;
    //	float quality_minimum,
    float quality_reward,quality_decay,detection_rate,finish_line;
    int minimum_contributions;
    float quality_total, quality_avg, ma_quality_lo, ma_quality_total, ma_quality_avg, maa_quality_avg;
    
    // current average (this sample) for range n
    float a_freq_range[BD_DETECTION_RANGES];
    // moving average of frequency range n
    float ma_freq_range[BD_DETECTION_RANGES];
    // moving average of moving average of frequency range n
    float maa_freq_range[BD_DETECTION_RANGES];
    // timestamp of last detection for frequecy range n
    float last_detection[BD_DETECTION_RANGES];
    
    // moving average of gap lengths
    float ma_bpm_range[BD_DETECTION_RANGES];
    // moving average of moving average of gap lengths
    float maa_bpm_range[BD_DETECTION_RANGES];
    
    // range n quality attribute, good match = quality+, bad match = quality-, min = 0
    float detection_quality[BD_DETECTION_RANGES];
    
    // current trigger state for range n
    bool detection[BD_DETECTION_RANGES];
    
    std::map<int,float> bpm_contest;	// 1/10th
    std::map<int,float> bpm_contest_lo; // 1/1
    
#if DEVTEST_BUILD
    bool debugmode;
    std::map<int,int> contribution_counter;
#endif
    
    BeatDetektor(float BPM_MIN_in=100.0,float BPM_MAX_in=200.0, BeatDetektor *link_src = NULL) :
    
    current_bpm(0.0),
    winning_bpm(0.0),
    win_val(0.0),
    win_bpm_int(0),
    win_val_lo(0.0),
    win_bpm_int_lo(0),
    
    bpm_predict(0),
    
    is_erratic(false),
    bpm_offset(0.0),
    last_timer(0.0),
    last_update(0.0),
    total_time(0.0),
    
    bpm_timer(0.0),
    beat_counter(0),
    half_counter(0),
    quarter_counter(0),
    src(link_src),
    
    //	quality_minimum(BD_QUALITY_MINIMUM),
    quality_reward(BD_QUALITY_REWARD),
    detection_rate(BD_DETECTION_RATE),
    finish_line(BD_FINISH_LINE),
    minimum_contributions(BD_MINIMUM_CONTRIBUTIONS),
    detection_factor(BD_DETECTION_FACTOR),
    quality_total(1.0),
    quality_avg(1.0),
    quality_decay(BD_QUALITY_DECAY),
    ma_quality_avg(0.001),
    ma_quality_lo(1.0),
    ma_quality_total(1.0)
#if DEVTEST_BUILD
    ,debugmode(false)
#endif
    
    {
        BPM_MIN = BPM_MIN_in;
        BPM_MAX = BPM_MAX_in;
        reset();
    }
    
    void reset(bool reset_freq=true)
    {
        for (int i = 0; i < BD_DETECTION_RANGES; i++)
        {
            //			ma_bpm_range[i] = maa_bpm_range[i] = 60.0/(float)(BPM_MIN + (1.0+sin(8.0*M_PI*((float)i/(float)BD_DETECTION_RANGES))/2.0)*((BPM_MAX-BPM_MIN)/2));
            ma_bpm_range[i] = maa_bpm_range[i] = 60.0/(float)(BPM_MIN+5)+ ((60.0/(float)(BPM_MAX-5)-60.0/(float)(BPM_MIN+5)) * ((float)i/(float)BD_DETECTION_RANGES));
            if (reset_freq)
            {
                a_freq_range[i] = ma_freq_range[i] = maa_freq_range[i] = 0;
            }
            last_detection[i] = 0;
            detection_quality[i] = 0;
            detection[i] = false;
            
        }
        
        total_time = 0;
        maa_quality_avg = 500.0;
        bpm_offset = bpm_timer = last_update = last_timer = winning_bpm = current_bpm = win_val = win_bpm_int = 0;
        bpm_contest.clear();
        bpm_contest_lo.clear();
#if DEVTEST_BUILD
        contribution_counter.clear();
#endif
    }
    
    void process(float timer_seconds, std::vector<float> &fft_data);
};



#endif /* utils_hpp */
