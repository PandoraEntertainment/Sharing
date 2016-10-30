#include "SharingPrivatePCH.h"
#include "SharingSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogSharing);

#define LOCTEXT_NAMESPACE "Sharing"

class FSharing : public ISharing
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FSharing, Sharing )

void FSharing::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Sharing",
										 LOCTEXT("RuntimeSettingsName", "Sharing"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Sharing plugin"),
										 GetMutableDefault<USharingSettings>()
										 );
	}

#if PLATFORM_ANDROID
	USharingFunctions::InitJavaFunctions();
#endif
}


void FSharing::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
