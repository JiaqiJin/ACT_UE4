// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "INKING/INKINGGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeINKINGGameMode() {}
// Cross Module References
	INKING_API UClass* Z_Construct_UClass_AINKINGGameMode_NoRegister();
	INKING_API UClass* Z_Construct_UClass_AINKINGGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_INKING();
// End Cross Module References
	void AINKINGGameMode::StaticRegisterNativesAINKINGGameMode()
	{
	}
	UClass* Z_Construct_UClass_AINKINGGameMode_NoRegister()
	{
		return AINKINGGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AINKINGGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AINKINGGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_INKING,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AINKINGGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "INKINGGameMode.h" },
		{ "ModuleRelativePath", "INKINGGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AINKINGGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AINKINGGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AINKINGGameMode_Statics::ClassParams = {
		&AINKINGGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AINKINGGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AINKINGGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AINKINGGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AINKINGGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AINKINGGameMode, 1473775944);
	template<> INKING_API UClass* StaticClass<AINKINGGameMode>()
	{
		return AINKINGGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AINKINGGameMode(Z_Construct_UClass_AINKINGGameMode, &AINKINGGameMode::StaticClass, TEXT("/Script/INKING"), TEXT("AINKINGGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AINKINGGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
