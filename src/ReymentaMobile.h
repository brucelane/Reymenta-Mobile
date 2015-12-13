//
// Created by bruce on 12/13/15.
//

#ifndef REYMENTAMOBILE_REYMENTAMOBILE_H
#define REYMENTAMOBILE_REYMENTAMOBILE_H

#endif //REYMENTAMOBILE_REYMENTAMOBILE_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/System.h"
#include "cinder/Rand.h"
#include "cinder/Log.h"
//#include "Cinder-imgui.h"

#include <vector>
#include <map>
#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

struct TouchPoint {
    TouchPoint() {}
    TouchPoint( const vec2 &initialPt, const Color &color ) : mColor( color ), mTimeOfDeath( -1.0 )
    {
        mLine.push_back( initialPt );
    }

    void addPoint( const vec2 &pt ) { mLine.push_back( pt ); }

    void draw() const
    {
        if( mTimeOfDeath > 0 ) // are we dying? then fade out
            gl::color( ColorA( mColor, ( mTimeOfDeath - getElapsedSeconds() ) / 2.0f ) );
        else
            gl::color( mColor );

        gl::draw( mLine );
    }

    void startDying() { mTimeOfDeath = getElapsedSeconds() + 2.0f; } // two seconds til dead

    bool isDead() const { return getElapsedSeconds() > mTimeOfDeath; }

    PolyLine2f		mLine;
    Color			mColor;
    float			mTimeOfDeath;
};

class ReymentaMobile : public App {
public:
    void	mouseDown( MouseEvent event ) override;
    void	mouseDrag( MouseEvent event ) override;

    void	touchesBegan( TouchEvent event ) override;
    void	touchesMoved( TouchEvent event ) override;
    void	touchesEnded( TouchEvent event ) override;

    void	setup() override;
    void	draw() override;

private:
    map<uint32_t,TouchPoint>	mActivePoints;
    list<TouchPoint>			mDyingPoints;
};
