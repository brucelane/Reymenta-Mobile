
#include "ReymentaMobile.h"

void prepareSettings( ReymentaMobile::Settings *settings )
{
	// By default, multi-touch is disabled on desktop and enabled on mobile platforms.
	// You enable multi-touch from the SettingsFn that fires before the app is constructed.
	settings->setMultiTouchEnabled( true );

	// On mobile, if you disable multitouch then touch events will arrive via mouseDown(), mouseDrag(), etc.
//	settings->setMultiTouchEnabled( false );
}

void ReymentaMobile::setup()
{
	CI_LOG_I( "MT: " << System::hasMultiTouch() << " Max points: " << System::getMaxMultiTouchPoints() );
	// set ui window and io events callbacks
    //ui::initialize(ui::Options().autoRender(false));
    ui::initialize();

}

void ReymentaMobile::touchesBegan( TouchEvent event )
{
	//CI_LOG_I( event );

	for( const auto &touch : event.getTouches() ) {
		ColorA newColor( CM_HSV, Rand::randFloat(), 1, 1 );
		mActivePoints.insert( make_pair( touch.getId(), TouchPoint( touch.getPos(), newColor ) ) );
	}
}

void ReymentaMobile::touchesMoved( TouchEvent event )
{
	//CI_LOG_I( event );
	for( const auto &touch : event.getTouches() ) {
		mActivePoints[touch.getId()].addPoint( touch.getPos() );
	}
}

void ReymentaMobile::touchesEnded( TouchEvent event )
{
	//CI_LOG_I( event );
	for( const auto &touch : event.getTouches() ) {
		mActivePoints[touch.getId()].startDying();
		mDyingPoints.push_back( mActivePoints[touch.getId()] );
		mActivePoints.erase( touch.getId() );
	}
}

void ReymentaMobile::mouseDown( MouseEvent event )
{
	CI_LOG_I( "right: " << boolalpha << event.isRight() << " , control down " << event.isControlDown() << dec );
}

void ReymentaMobile::mouseDrag( MouseEvent event )
{
	CI_LOG_I( "pos: " << event.getPos() );
}

void ReymentaMobile::draw()
{
	gl::enableAlphaBlending();
	gl::clear( ColorA( 0.1f, 0.1f, 0.1f, 1.0f ) );

	for( const auto &activePoint : mActivePoints ) {
		activePoint.second.draw();
	}

	for( auto dyingIt = mDyingPoints.begin(); dyingIt != mDyingPoints.end(); ) {
		dyingIt->draw();
		if( dyingIt->isDead() )
			dyingIt = mDyingPoints.erase( dyingIt );
		else
			++dyingIt;
	}
	
	// draw yellow circles at the active touch points
	gl::color( ColorA( 1, 1, 0, 1 ) );
	for( const auto &touch : getActiveTouches() )
		gl::drawStrokedCircle( touch.getPos(), 20 );
}

CINDER_APP( ReymentaMobile, RendererGl, prepareSettings )
