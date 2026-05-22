// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UniGDEVMechanicCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeUniGDEVMechanicCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AUniGDEVMechanicCameraManager();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AUniGDEVMechanicCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_UniGDEVMechanic();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AUniGDEVMechanicCameraManager ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager;
UClass* AUniGDEVMechanicCameraManager::GetPrivateStaticClass()
{
	using TClass = AUniGDEVMechanicCameraManager;
	if (!Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("UniGDEVMechanicCameraManager"),
			Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager.InnerSingleton,
			StaticRegisterNativesAUniGDEVMechanicCameraManager,
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
	return Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AUniGDEVMechanicCameraManager_NoRegister()
{
	return AUniGDEVMechanicCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "UniGDEVMechanicCameraManager.h" },
		{ "ModuleRelativePath", "UniGDEVMechanicCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AUniGDEVMechanicCameraManager constinit property declarations ************
// ********** End Class AUniGDEVMechanicCameraManager constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUniGDEVMechanicCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics
UObject* (*const Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_UniGDEVMechanic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics::ClassParams = {
	&AUniGDEVMechanicCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics::Class_MetaDataParams)
};
void AUniGDEVMechanicCameraManager::StaticRegisterNativesAUniGDEVMechanicCameraManager()
{
}
UClass* Z_Construct_UClass_AUniGDEVMechanicCameraManager()
{
	if (!Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager.OuterSingleton, Z_Construct_UClass_AUniGDEVMechanicCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AUniGDEVMechanicCameraManager);
AUniGDEVMechanicCameraManager::~AUniGDEVMechanicCameraManager() {}
// ********** End Class AUniGDEVMechanicCameraManager **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCameraManager_h__Script_UniGDEVMechanic_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUniGDEVMechanicCameraManager, AUniGDEVMechanicCameraManager::StaticClass, TEXT("AUniGDEVMechanicCameraManager"), &Z_Registration_Info_UClass_AUniGDEVMechanicCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUniGDEVMechanicCameraManager), 1428576978U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCameraManager_h__Script_UniGDEVMechanic_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCameraManager_h__Script_UniGDEVMechanic_2873433881{
	TEXT("/Script/UniGDEVMechanic"),
	Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCameraManager_h__Script_UniGDEVMechanic_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCameraManager_h__Script_UniGDEVMechanic_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
