// For conditions of distribution and use, see copyright notice in license.txt

#ifndef incl_OgreRenderer_OgreMaterialResource_h
#define incl_OgreRenderer_OgreMaterialResource_h

#include "AssetInterface.h"
#include "ResourceInterface.h"
#include "OgreModuleApi.h"

#include <OgreMaterial.h>

namespace OgreRenderer
{
    class OgreMaterialResource;
    typedef boost::shared_ptr<OgreMaterialResource> OgreMaterialResourcePtr;

    //! An Ogre-specific mesh resource
    /*! \ingroup OgreRenderingModuleClient
     */
    class OGRE_MODULE_API OgreMaterialResource : public Foundation::ResourceInterface
    {
    public:
        //! Generates an empty unloaded material resource.
        /*! \param id The resource ID that is associated to this material.
         */
        explicit OgreMaterialResource(const std::string& id);
        
        //! constructor
        /*! \param id mesh id
            \param source asset data to construct mesh from
        */
        OgreMaterialResource(const std::string& id, Foundation::AssetPtr source);

        //! destructor
        virtual ~OgreMaterialResource();

        //! returns resource type in text form
        virtual const std::string& GetType() const;

        //! returns Ogre mesh
        /*! may be null if no data successfully set yet
         */
        Ogre::MaterialPtr GetMaterial() const { return ogre_material_; }

        //! sets contents from asset data
        /*! \param source asset data to construct the material from
            \return true if successful
        */
        bool SetData(Foundation::AssetPtr source);

        //! returns resource type in text form (static)
        static const std::string& GetTypeStatic();

    private:
        Ogre::MaterialPtr ogre_material_;
        
        //! Deinitializes the material and frees all Ogre-side structures as well.
        void RemoveMaterial();
    };
}

#endif