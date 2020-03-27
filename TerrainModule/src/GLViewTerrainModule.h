#pragma once

#include "GLView.h"

#include "PxPhysicsAPI.h"

#include <map>

namespace Aftr
{
   class Camera;

/**
   \class GLViewTerrainModule
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewTerrainModule : public GLView
{
public:
   static GLViewTerrainModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewTerrainModule();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createTerrainModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   void init(float gravityScalar = Aftr::GRAVITY,
	   Vector gravityNormalizedVector = Vector(0, 0, -1),
	   std::string confFileName = "Aftr.conf",
	   const PHYSICS_ENGINE_TYPE& physicsEngineType = PHYSICS_ENGINE_TYPE::petODE);
   void shutdownEngine();

   WO* track_sphere;
   std::map<WO*, int> placed_cubes; // Keep track of the cubes separately from the world list to keep in sync

protected:
   GLViewTerrainModule( const std::vector< std::string >& args );
   void createGrid();
   void createTriangleMesh(WO* wo);
   virtual void onCreate();  

   Vector centerOfWorld;
   Vector gravityDirection;

};

/** \} */

} //namespace Aftr
