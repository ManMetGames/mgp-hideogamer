// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUniGDEVMechanic_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	UNIGDEVMECHANIC_API UFunction* Z_Construct_UDelegateFunction_UniGDEVMechanic_BulletCountUpdatedDelegate__DelegateSignature();
	UNIGDEVMECHANIC_API UFunction* Z_Construct_UDelegateFunction_UniGDEVMechanic_DamagedDelegate__DelegateSignature();
	UNIGDEVMECHANIC_API UFunction* Z_Construct_UDelegateFunction_UniGDEVMechanic_PawnDeathDelegate__DelegateSignature();
	UNIGDEVMECHANIC_API UFunction* Z_Construct_UDelegateFunction_UniGDEVMechanic_SprintStateChangedDelegate__DelegateSignature();
	UNIGDEVMECHANIC_API UFunction* Z_Construct_UDelegateFunction_UniGDEVMechanic_UpdateSprintMeterDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UniGDEVMechanic;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UniGDEVMechanic()
	{
		if (!Z_Registration_Info_UPackage__Script_UniGDEVMechanic.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_UniGDEVMechanic_BulletCountUpdatedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_UniGDEVMechanic_DamagedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_UniGDEVMechanic_PawnDeathDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_UniGDEVMechanic_SprintStateChangedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_UniGDEVMechanic_UpdateSprintMeterDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/UniGDEVMechanic",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xCF7D781C,
			0x5BB65726,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UniGDEVMechanic.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_UniGDEVMechanic.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UniGDEVMechanic(Z_Construct_UPackage__Script_UniGDEVMechanic, TEXT("/Script/UniGDEVMechanic"), Z_Registration_Info_UPackage__Script_UniGDEVMechanic, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xCF7D781C, 0x5BB65726));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
