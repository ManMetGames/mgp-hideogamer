// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GrappleHook.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGrappleHook() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AGrappleHook();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AGrappleHook_NoRegister();
UPackage* Z_Construct_UPackage__Script_UniGDEVMechanic();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AGrappleHook *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AGrappleHook;
UClass* AGrappleHook::GetPrivateStaticClass()
{
	using TClass = AGrappleHook;
	if (!Z_Registration_Info_UClass_AGrappleHook.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GrappleHook"),
			Z_Registration_Info_UClass_AGrappleHook.InnerSingleton,
			StaticRegisterNativesAGrappleHook,
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
	return Z_Registration_Info_UClass_AGrappleHook.InnerSingleton;
}
UClass* Z_Construct_UClass_AGrappleHook_NoRegister()
{
	return AGrappleHook::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AGrappleHook_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GrappleHook.h" },
		{ "ModuleRelativePath", "Public/GrappleHook.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGrappleHook constinit property declarations *****************************
// ********** End Class AGrappleHook constinit property declarations *******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGrappleHook>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AGrappleHook_Statics
UObject* (*const Z_Construct_UClass_AGrappleHook_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UniGDEVMechanic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGrappleHook_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGrappleHook_Statics::ClassParams = {
	&AGrappleHook::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGrappleHook_Statics::Class_MetaDataParams), Z_Construct_UClass_AGrappleHook_Statics::Class_MetaDataParams)
};
void AGrappleHook::StaticRegisterNativesAGrappleHook()
{
}
UClass* Z_Construct_UClass_AGrappleHook()
{
	if (!Z_Registration_Info_UClass_AGrappleHook.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGrappleHook.OuterSingleton, Z_Construct_UClass_AGrappleHook_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGrappleHook.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGrappleHook);
AGrappleHook::~AGrappleHook() {}
// ********** End Class AGrappleHook ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_Public_GrappleHook_h__Script_UniGDEVMechanic_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGrappleHook, AGrappleHook::StaticClass, TEXT("AGrappleHook"), &Z_Registration_Info_UClass_AGrappleHook, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGrappleHook), 395481501U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_Public_GrappleHook_h__Script_UniGDEVMechanic_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_Public_GrappleHook_h__Script_UniGDEVMechanic_1245416593{
	TEXT("/Script/UniGDEVMechanic"),
	Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_Public_GrappleHook_h__Script_UniGDEVMechanic_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_Public_GrappleHook_h__Script_UniGDEVMechanic_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
