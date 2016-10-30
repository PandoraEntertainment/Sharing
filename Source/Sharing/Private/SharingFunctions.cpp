
#include "SharingPrivatePCH.h"


#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"


#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

DECLARE_JAVA_METHOD(AndroidThunkJava_Sharing_ShareScreenshotText);
DECLARE_JAVA_METHOD(AndroidThunkJava_Sharing_ShareTextUrl);

void USharingFunctions::InitJavaFunctions()
{
	
	//INIT_JAVA_METHOD(AndroidThunkJava_Sharing_ShareScreenshot, "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	//INIT_JAVA_METHOD(AndroidThunkJava_Sharing_ShareTextUrl, "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_Sharing_ShareTextUrl, "(Ljava/lang/String;Ljava/lang/String;)V");
	//INIT_JAVA_METHOD(AndroidThunkJava_Sharing_ShareScreenshotText, "(Ljava/lang/String;Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_Sharing_ShareScreenshotText, "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD
#endif


void USharingFunctions::shareScreenshotText(FString Subject, FString Message, FString AppName, FString Filename) {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring MessageArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Message));
		jstring AppNameArg = Env->NewStringUTF(TCHAR_TO_UTF8(*AppName));
		jstring FilenameArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Filename));
		jstring SubjectArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Subject));

		//FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Sharing_ShareScreenshot, SubjectArg , MessageArg, UrlArg);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Sharing_ShareScreenshotText, SubjectArg, MessageArg, AppNameArg, FilenameArg);

		Env->DeleteLocalRef(MessageArg);
		Env->DeleteLocalRef(AppNameArg);
		Env->DeleteLocalRef(FilenameArg);
		Env->DeleteLocalRef(SubjectArg);
		

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method shareScreenshotText\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}


void USharingFunctions::shareTextUrl(FString Subject, FString Message) {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring MessageArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Message));
		//jstring UrlArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Url));
		jstring SubjectArg = Env->NewStringUTF(TCHAR_TO_UTF8(*Subject));

		//FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Sharing_ShareTextUrl, SubjectArg , MessageArg, UrlArg);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Sharing_ShareTextUrl, SubjectArg, MessageArg);

		Env->DeleteLocalRef(MessageArg);
		//Env->DeleteLocalRef(UrlArg);
		Env->DeleteLocalRef(SubjectArg);

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method shareTextUrl\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}


void USharingFunctions::Screenshot(FString filename) {

	FScreenshotRequest::RequestScreenshot(filename, true, false);

}

FString USharingFunctions::ScreenshotPath() {

	return FPaths::ConvertRelativePathToFull(FPaths::ScreenShotDir());

}

FString USharingFunctions::GamePath() {

	return FPaths::ConvertRelativePathToFull(FPaths::GameDir());

}


void USharingFunctions::MoveScreenshot(FString filename) {

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	FString AbsoluteSourcePath = ScreenshotPath() + "/Game.png";
	FString AbsoluteDestinationPath = GamePath() + "/Game2.png";

	PlatformFile.MoveFile(*AbsoluteDestinationPath, *AbsoluteSourcePath);

}