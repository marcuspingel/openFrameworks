/*
 *  AVFoundationVideoGrabber.h
 */

#pragma once

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CoreVideo.h>
#import <CoreMedia/CoreMedia.h>
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#if defined  __arm__

class AVFoundationVideoGrabber;


@interface iOSVideoGrabber : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate> {

	@public
	CGImageRef currentFrame;	
	
	int width;
	int height;
	
	BOOL bInitCalled;
	int deviceID;

	AVFoundationVideoGrabber * grabberPtr;
}

-(BOOL)initCapture:(int)framerate capWidth:(int)w capHeight:(int)h;
-(void)startCapture;
-(void)stopCapture;
-(void)lockExposureAndFocus;
-(vector <string>)listDevices;
-(void)setDevice:(int)_device;
-(void)eraseGrabberPtr;

-(CGImageRef)getCurrentFrame;

@end

class AVFoundationVideoGrabber{

	public:		
		AVFoundationVideoGrabber();
		~AVFoundationVideoGrabber();
		
		void clear();
		void setCaptureRate(int capRate);
	
        bool initGrabber(int w, int h);
        bool isInitialized();
		void updatePixelsCB( CGImageRef & ref );
	
		void update();
	
		bool isFrameNew();
		
		vector <ofVideoDevice> listDevices();
		void setDevice(int deviceID);
		bool setPixelFormat(ofPixelFormat PixelFormat);
		ofPixelFormat getPixelFormat();
	
		unsigned char * getPixels(){
			return pixels;
		}
		float getWidth(){
			return width;
		}
		float getHeight(){
			return height;
		}
	
		GLint internalGlDataType;
		unsigned char * pixels;
		bool newFrame;
		bool bLock;
	
		int width, height;
	
	protected:
		
		
		int device;
        bool bIsInit;
		bool bHavePixelsChanged;
		
		int fps;
		ofTexture tex;
		iOSVideoGrabber * grabber;
		GLubyte *pixelsTmp;
};


#endif	// (__arm__) compile only for ARM

