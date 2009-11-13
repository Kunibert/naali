// For conditions of distribution and use, see copyright notice in license.txt

#ifndef incl_ProtocolUtilities_WorldSessionInterface_h
#define incl_ProtocolUtilities_WorldSessionInterface_h

#include "Foundation.h"
#include "LoginCredentialsInterface.h"

#include <QObject>
#include <QUrl>

namespace ProtocolUtilities
{
	class WorldSessionInterface : public QObject
	{

	Q_OBJECT 

	public:

        //! Connection UrlType
		enum UrlType
		{
			OpenSimServer = 0,
			OpenSimGridServer,
			RealXtendAuthenticationServer
		};

		//! Performs login, should later return WorldStream etc (CAPS?)
		virtual bool StartSession(LoginCredentialsInterface *credentials, QUrl *serverEntryPointUrl) = 0;

		//! Make Url validation according to type
		virtual QUrl ValidateUrl(const QString urlString, const UrlType urlType) = 0;

		//! Get login credentials
		virtual LoginCredentialsInterface* GetCredentials() const = 0;

		//! Get server entry point url. Used for xmlrpc login_to_simulator and authentication internally.
		virtual QUrl GetServerEntryPointUrl() const = 0;

		//! Get created WorldStream: void -> WorldStreamInterface when implemented
		virtual void GetWorldStream() const = 0;

		//! Set login credentials
		virtual void SetCredentials(LoginCredentialsInterface *newCredentials) = 0;

		//! Set server entry point url
		virtual void SetServerEntryPointUrl(const QUrl &newUrl) = 0;

		//! Logging functionality
		MODULE_LOGGING_FUNCTIONS;
        //! returns name of this module. Needed for logging.
		static const std::string &NameStatic() { return std::string("ProtocolUtilities"); }
		static const Foundation::Module::Type type_static_ = Foundation::Module::MT_Unknown;

	};

}

#endif // incl_RexLogic_WorldSessionInterface_h