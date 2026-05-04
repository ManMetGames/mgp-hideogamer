// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UniGDEVMechanicGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeUniGDEVMechanicGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AUniGDEVMechanicGameMode();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AUniGDEVMechanicGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_UniGDEVMechanic();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AUniGDEVMechanicGameMode *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AUniGDEVMechanicGameMode;
UClass* AUniGDEVMechanicGameMode::GetPrivateStaticClass()
{
	using TClass = AUniGDEVMechanicGameMode;
	if (!Z_Registration_Info_UClass_AUniGDEVMechanicGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("UniGDEVMechanicGameMode"),
			Z_Registration_Info_UClass_AUniGDEVMechanicGameMode.InnerSingleton,
			StaticRegisterNativesAUniGDEVMechanicGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AUniGDEVMechanicGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AUniGDEVMechanicGameMode_NoRegister()
{
	return AUniGDEVMechanicGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UniGDEVMechanicGameMode.h" },
		{ "ModuleRelativePath", "UniGDEVMechanicGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AUniGDEVMechanicGameMode constinit property declarations *****************
// ********** End Class AUniGDEVMechanicGameMode constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUniGDEVMechanicGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics
UObject* (*const Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_UniGDEVMechanic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics::ClassParams = {
	&AUniGDEVMechanicGameMode::StaticClass,
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
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics::Class_MetaDataParams)
};
void AUniGDEVMechanicGameMode::StaticRegisterNativesAUniGDEVMechanicGameMode()
{
}
UClass* Z_Construct_UClass_AUniGDEVMechanicGameMode()
{
	if (!Z_Registration_Info_UClass_AUniGDEVMechanicGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUniGDEVMechanicGameMode.OuterSingleton, Z_Construct_UClass_AUniGDEVMechanicGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUniGDEVMechanicGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AUniGDEVMechanicGameMode);
AUniGDEVMechanicGameMode::~AUniGDEVMechanicGameMode() {}
// ********** End Class AUniGDEVMechanicGameMode ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicGameMode_h__Script_UniGDEVMechanic_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUniGDEVMechanicGameMode, AUniGDEVMechanicGameMode::StaticClass, TEXT("AUniGDEVMechanicGameMode"), &Z_Registration_Info_UClass_AUniGDEVMechanicGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUniGDEVMechanicGameMode), 631182724U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicGameMode_h__Script_UniGDEVMechanic_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicGameMode_h__Script_UniGDEVMechanic_3867126904{
	TEXT("/Script/UniGDEVMechanic"),
	Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicGameMode_h__Script_UniGDEVMechanic_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicGameMode_h__Script_UniGDEVMechanic_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
