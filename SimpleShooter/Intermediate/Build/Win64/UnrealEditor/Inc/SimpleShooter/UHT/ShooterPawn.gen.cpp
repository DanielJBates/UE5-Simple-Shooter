// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/ShooterPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooterPawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterPawn();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void AShooterPawn::StaticRegisterNativesAShooterPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AShooterPawn);
	UClass* Z_Construct_UClass_AShooterPawn_NoRegister()
	{
		return AShooterPawn::StaticClass();
	}
	struct Z_Construct_UClass_AShooterPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooterPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterPawn_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ShooterPawn.h" },
		{ "ModuleRelativePath", "ShooterPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooterPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooterPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AShooterPawn_Statics::ClassParams = {
		&AShooterPawn::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AShooterPawn_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AShooterPawn()
	{
		if (!Z_Registration_Info_UClass_AShooterPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AShooterPawn.OuterSingleton, Z_Construct_UClass_AShooterPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AShooterPawn.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AShooterPawn>()
	{
		return AShooterPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShooterPawn);
	AShooterPawn::~AShooterPawn() {}
	struct Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AShooterPawn, AShooterPawn::StaticClass, TEXT("AShooterPawn"), &Z_Registration_Info_UClass_AShooterPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShooterPawn), 2588557572U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterPawn_h_2142316360(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
