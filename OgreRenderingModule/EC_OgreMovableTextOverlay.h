// For conditions of distribution and use, see copyright notice in license.txt

#ifndef incl_OgreRenderer_EC_OgreMovableTextOverlay_h
#define incl_OgreRenderer_EC_OgreMovableTextOverlay_h

#include "ComponentInterface.h"
#include "Foundation.h"
#include "OgreModuleApi.h"

#include <OgreVector2.h>

namespace Ogre
{
    class TextAreaOverlayElement;
    class OverlayContainer;
    class Overlay;
    class SceneNode;
    class MovableObject;
    class Camera;
    class Vector2;
    class Font;
}

namespace OgreRenderer
{
    class Renderer;
    typedef boost::shared_ptr<Renderer> RendererPtr;
    
    //! Movable Ogre text overlay.
    /*! \ingroup OgreRenderingModuleClient
     */
    class OGRE_MODULE_API EC_OgreMovableTextOverlay : public Foundation::ComponentInterface
    {
        DECLARE_EC(EC_OgreMovableTextOverlay);
    private:
        //! constructor
        /*! \param module renderer module
         */
        EC_OgreMovableTextOverlay(Foundation::ModuleInterface* module);

        //! copy constructor. 
//        EC_OgreMovableTextOverlay(const EC_OgreMovableTextOverlay &other);

    public:
        //! destructor
        virtual ~EC_OgreMovableTextOverlay();

        //! assignment operator. See copy constructor
//        EC_OgreMovableTextOverlay &operator ==(const EC_OgreTextOverlay &other) { assert (false); return *this; }
        
        //! Sets the scene node which the overlay is meant to follow.
        void SetParentNode(Ogre::SceneNode *parent_node);
        
        //! displays the text as is in the overlay
        void SetText(const std::string &text);

        //! hide / show the overlay
        void SetVisible(bool visible);

        //! @return True if the overlay is visible, false otherwise.
        bool IsVisible() const;

        //! Updates the text overlay and container position and dimension.
        void Update();
        
    private:
        //! Create the Ogre overlay
        void CreateOverlay();
        
        //! return the dimensions of the text.
        Ogre::Vector2 GetTextDimensions(const std::string &text);
        
        //! Overlay element for the text.
        Ogre::TextAreaOverlayElement *text_element_;

        //! container for overlay text.
        Ogre::OverlayContainer *container_;

        //! Overlay for the text.
        Ogre::Overlay *overlay_;
        
        //! SceneNode for the overlay text position.
        Ogre::SceneNode *node_;
        
        //! Camera.
        const Ogre::Camera *camera_;
        
        //! Unique object name for the overlay.
        std::string overlayName_;

        //! Unique object name for the overlay container.
        std::string containerName_;
                
        //! The overlay text.
        std::string text_;
        
        //! Font which the overlay text uses.
        Ogre::Font *font_;
        
        //! Overlay text dimensions.
        Ogre::Vector2 textDim_;
        
        //! Font height
//        const Core::Real char_height_;

        //! Is the text visible
        bool visible_;

        //! The renderer, need reference to check if renderer is still alive.
        boost::weak_ptr<Renderer> renderer_;
        
        //! The window width during the overlay construction.
        int windowWidth_;
        
        //! The window height during the overlay construction.
        int windowHeight_;
    };
}

#endif