#pragma once

#include "SharingFunctions.generated.h"

UCLASS(NotBlueprintable)
class USharingFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif
	
	//UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
	//static void shareScreenshot(FString Subject, FString Message, FString Url);

	//UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
	//static void shareTextUrl(FString Subject, FString Message, FString Url);



	/**Share text */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
	static void shareTextUrl(FString Subject, FString Message);

	/**Screenshot */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
	static void Screenshot(FString filename);

	/**Return Screenshot Directory */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
	static FString ScreenshotPath();

	/**Return Game Directory */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
    static FString GamePath();

	/**Share text  and image */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
	static void shareScreenshotText(FString Subject, FString Message, FString AppName, FString Filename);

	/**Move Screenshot */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "Sharing"), Category = "Sharing")
    static void MoveScreenshot(FString filename);
};
