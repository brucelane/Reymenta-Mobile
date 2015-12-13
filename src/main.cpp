#include "ofMain.h"
#include "ofApp.h"
//#if (OF_VERSION_MINOR != 9) && defined(TARGET_OPENGLES)
#include "ofGLProgrammableRenderer.h"
//#endif
int main(){
	ofGLWindowSettings glWindowSettings;
	glWindowSettings.width = 1280;
	glWindowSettings.height = 720;
	glWindowSettings.setGLVersion(3, 2);
	ofCreateWindow(glWindowSettings);
	//ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp() );
	return 0;
}


#ifdef TARGET_ANDROID
#include <jni.h>

//========================================================================
extern "C"{
	void Java_cc_openframeworks_OFAndroid_init( JNIEnv*  env, jobject  thiz ){
		main();
	}
}
#endif
