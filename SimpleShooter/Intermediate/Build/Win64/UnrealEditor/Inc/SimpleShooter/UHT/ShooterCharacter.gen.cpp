// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/ShooterCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooterCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterCharacter();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void AShooterCharacter::StaticRegisterNativesAShooterCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AShooterCharacter);
	UClass* Z_Construct_UClass_AShooterCharacter_NoRegister()
	{
		return AShooterCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AShooterCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShooterMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ShooterMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookRateInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookRateInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireInputAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FireInputAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotationRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AShooterCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ShooterCharacter.h" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_ShooterMappingContext_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_ShooterMappingContext = { "ShooterMappingContext", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, ShooterMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_ShooterMappingContext_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_ShooterMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_MoveInputAction_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_MoveInputAction = { "MoveInputAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, MoveInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_MoveInputAction_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_MoveInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookInputAction_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookInputAction = { "LookInputAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, LookInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookInputAction_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookRateInputAction_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookRateInputAction = { "LookRateInputAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, LookRateInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookRateInputAction_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookRateInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_JumpInputAction_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_JumpInputAction = { "JumpInputAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, JumpInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_JumpInputAction_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_JumpInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_FireInputAction_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_FireInputAction = { "FireInputAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, FireInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_FireInputAction_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_FireInputAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AShooterCharacter_Statics::NewProp_RotationRate_MetaData[] = {
		{ "Category", "Player Input" },
		{ "ModuleRelativePath", "ShooterCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooterCharacter_Statics::NewProp_RotationRate = { "RotationRate", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterCharacter, RotationRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::NewProp_RotationRate_MetaData), Z_Construct_UClass_AShooterCharacter_Statics::NewProp_RotationRate_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShooterCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_ShooterMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_MoveInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_LookRateInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_JumpInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_FireInputAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterCharacter_Statics::NewProp_RotationRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AShooterCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooterCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AShooterCharacter_Statics::ClassParams = {
		&AShooterCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AShooterCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AShooterCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AShooterCharacter()
	{
		if (!Z_Registration_Info_UClass_AShooterCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AShooterCharacter.OuterSingleton, Z_Construct_UClass_AShooterCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AShooterCharacter.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AShooterCharacter>()
	{
		return AShooterCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AShooterCharacter);
	AShooterCharacter::~AShooterCharacter() {}
	struct Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AShooterCharacter, AShooterCharacter::StaticClass, TEXT("AShooterCharacter"), &Z_Registration_Info_UClass_AShooterCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShooterCharacter), 2908387053U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_1348421650(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
