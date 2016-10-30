

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class Sharing : ModuleRules
	{
		public Sharing(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"Developer/Sharing/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine"
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                    //"CoreUObject",
                    //"Engine",
                    //"InputCore",

                    //"RHI",
                    //"RenderCore",

                    //"HTTP",

                    //"UMG", "Slate", "SlateCore",
                    //"ImageWrapper",               
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
				
			PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"Settings",
                "Launch",
            }
            );


			if (Target.Platform == UnrealTargetPlatform.IOS) {
				
			

				PublicFrameworks.AddRange( 
					new string[] 
					{ 
						
					}
				);
			}
			else if(Target.Platform == UnrealTargetPlatform.Android)
			{
				string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
				AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "Sharing_APL.xml")));
			}
		}
	}
}
