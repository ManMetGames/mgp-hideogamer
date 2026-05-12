// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UniGDEVMechanicCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeUniGDEVMechanicCharacter() {}

// ********** Begin Cross Module References ********************************************************
CABLECOMPONENT_API UClass* Z_Construct_UClass_UCableComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AUniGDEVMechanicCharacter();
UNIGDEVMECHANIC_API UClass* Z_Construct_UClass_AUniGDEVMechanicCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_UniGDEVMechanic();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AUniGDEVMechanicCharacter Function DoAim *********************************
struct Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics
{
	struct UniGDEVMechanicCharacter_eventDoAim_Parms
	{
		float Yaw;
		float Pitch;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles aim inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles aim inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoAim constinit property declarations *********************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Pitch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoAim constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoAim Property Definitions ********************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::NewProp_Yaw = { "Yaw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UniGDEVMechanicCharacter_eventDoAim_Parms, Yaw), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::NewProp_Pitch = { "Pitch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UniGDEVMechanicCharacter_eventDoAim_Parms, Pitch), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::NewProp_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::NewProp_Pitch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::PropPointers) < 2048);
// ********** End Function DoAim Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AUniGDEVMechanicCharacter, nullptr, "DoAim", 	Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::UniGDEVMechanicCharacter_eventDoAim_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::UniGDEVMechanicCharacter_eventDoAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUniGDEVMechanicCharacter::execDoAim)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Yaw);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Pitch);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoAim(Z_Param_Yaw,Z_Param_Pitch);
	P_NATIVE_END;
}
// ********** End Class AUniGDEVMechanicCharacter Function DoAim ***********************************

// ********** Begin Class AUniGDEVMechanicCharacter Function DoJumpEnd *****************************
struct Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles jump end inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles jump end inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoJumpEnd constinit property declarations *****************************
// ********** End Function DoJumpEnd constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AUniGDEVMechanicCharacter, nullptr, "DoJumpEnd", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUniGDEVMechanicCharacter::execDoJumpEnd)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoJumpEnd();
	P_NATIVE_END;
}
// ********** End Class AUniGDEVMechanicCharacter Function DoJumpEnd *******************************

// ********** Begin Class AUniGDEVMechanicCharacter Function DoJumpStart ***************************
struct Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles jump start inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles jump start inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoJumpStart constinit property declarations ***************************
// ********** End Function DoJumpStart constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AUniGDEVMechanicCharacter, nullptr, "DoJumpStart", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUniGDEVMechanicCharacter::execDoJumpStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoJumpStart();
	P_NATIVE_END;
}
// ********** End Class AUniGDEVMechanicCharacter Function DoJumpStart *****************************

// ********** Begin Class AUniGDEVMechanicCharacter Function DoMove ********************************
struct Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics
{
	struct UniGDEVMechanicCharacter_eventDoMove_Parms
	{
		float Right;
		float Forward;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles move inputs from either controls or UI interfaces */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles move inputs from either controls or UI interfaces" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoMove constinit property declarations ********************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Right;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Forward;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoMove constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoMove Property Definitions *******************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UniGDEVMechanicCharacter_eventDoMove_Parms, Right), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::NewProp_Forward = { "Forward", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UniGDEVMechanicCharacter_eventDoMove_Parms, Forward), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::NewProp_Right,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::NewProp_Forward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::PropPointers) < 2048);
// ********** End Function DoMove Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AUniGDEVMechanicCharacter, nullptr, "DoMove", 	Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::UniGDEVMechanicCharacter_eventDoMove_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::UniGDEVMechanicCharacter_eventDoMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUniGDEVMechanicCharacter::execDoMove)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Right);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Forward);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoMove(Z_Param_Right,Z_Param_Forward);
	P_NATIVE_END;
}
// ********** End Class AUniGDEVMechanicCharacter Function DoMove **********************************

// ********** Begin Class AUniGDEVMechanicCharacter ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AUniGDEVMechanicCharacter;
UClass* AUniGDEVMechanicCharacter::GetPrivateStaticClass()
{
	using TClass = AUniGDEVMechanicCharacter;
	if (!Z_Registration_Info_UClass_AUniGDEVMechanicCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("UniGDEVMechanicCharacter"),
			Z_Registration_Info_UClass_AUniGDEVMechanicCharacter.InnerSingleton,
			StaticRegisterNativesAUniGDEVMechanicCharacter,
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
	return Z_Registration_Info_UClass_AUniGDEVMechanicCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AUniGDEVMechanicCharacter_NoRegister()
{
	return AUniGDEVMechanicCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A basic first person character\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "UniGDEVMechanicCharacter.h" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A basic first person character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstPersonMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pawn mesh: first person view (arms; seen only by self) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pawn mesh: first person view (arms; seen only by self)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstPersonCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** First person camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "First person camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseLookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mouse Look Input Action */" },
#endif
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mouse Look Input Action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrappleAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrappleCable_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grapple" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrappleStartLocation_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grapple" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrappleGun_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grapple" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UniGDEVMechanicCharacter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AUniGDEVMechanicCharacter constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstPersonMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstPersonCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MouseLookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrappleAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrappleCable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrappleStartLocation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrappleGun;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AUniGDEVMechanicCharacter constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DoAim"), .Pointer = &AUniGDEVMechanicCharacter::execDoAim },
		{ .NameUTF8 = UTF8TEXT("DoJumpEnd"), .Pointer = &AUniGDEVMechanicCharacter::execDoJumpEnd },
		{ .NameUTF8 = UTF8TEXT("DoJumpStart"), .Pointer = &AUniGDEVMechanicCharacter::execDoJumpStart },
		{ .NameUTF8 = UTF8TEXT("DoMove"), .Pointer = &AUniGDEVMechanicCharacter::execDoMove },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoAim, "DoAim" }, // 2116376194
		{ &Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpEnd, "DoJumpEnd" }, // 766329280
		{ &Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoJumpStart, "DoJumpStart" }, // 612226097
		{ &Z_Construct_UFunction_AUniGDEVMechanicCharacter_DoMove, "DoMove" }, // 3874356728
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUniGDEVMechanicCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics

// ********** Begin Class AUniGDEVMechanicCharacter Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_FirstPersonMesh = { "FirstPersonMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, FirstPersonMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstPersonMesh_MetaData), NewProp_FirstPersonMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_FirstPersonCameraComponent = { "FirstPersonCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, FirstPersonCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstPersonCameraComponent_MetaData), NewProp_FirstPersonCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_MouseLookAction = { "MouseLookAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, MouseLookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseLookAction_MetaData), NewProp_MouseLookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleAction = { "GrappleAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, GrappleAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrappleAction_MetaData), NewProp_GrappleAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleCable = { "GrappleCable", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, GrappleCable), Z_Construct_UClass_UCableComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrappleCable_MetaData), NewProp_GrappleCable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleStartLocation = { "GrappleStartLocation", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, GrappleStartLocation), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrappleStartLocation_MetaData), NewProp_GrappleStartLocation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleGun = { "GrappleGun", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUniGDEVMechanicCharacter, GrappleGun), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrappleGun_MetaData), NewProp_GrappleGun_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_FirstPersonMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_FirstPersonCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_MouseLookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleCable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleStartLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::NewProp_GrappleGun,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::PropPointers) < 2048);
// ********** End Class AUniGDEVMechanicCharacter Property Definitions *****************************
UObject* (*const Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_UniGDEVMechanic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::ClassParams = {
	&AUniGDEVMechanicCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::Class_MetaDataParams)
};
void AUniGDEVMechanicCharacter::StaticRegisterNativesAUniGDEVMechanicCharacter()
{
	UClass* Class = AUniGDEVMechanicCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::Funcs));
}
UClass* Z_Construct_UClass_AUniGDEVMechanicCharacter()
{
	if (!Z_Registration_Info_UClass_AUniGDEVMechanicCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUniGDEVMechanicCharacter.OuterSingleton, Z_Construct_UClass_AUniGDEVMechanicCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUniGDEVMechanicCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AUniGDEVMechanicCharacter);
AUniGDEVMechanicCharacter::~AUniGDEVMechanicCharacter() {}
// ********** End Class AUniGDEVMechanicCharacter **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCharacter_h__Script_UniGDEVMechanic_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUniGDEVMechanicCharacter, AUniGDEVMechanicCharacter::StaticClass, TEXT("AUniGDEVMechanicCharacter"), &Z_Registration_Info_UClass_AUniGDEVMechanicCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUniGDEVMechanicCharacter), 685530538U) },
	};
}; // Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCharacter_h__Script_UniGDEVMechanic_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCharacter_h__Script_UniGDEVMechanic_961452221{
	TEXT("/Script/UniGDEVMechanic"),
	Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCharacter_h__Script_UniGDEVMechanic_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Uni_Unreal_mgp_hideogamer_mgp_hideogamer_UniGDEVMechanic_Source_UniGDEVMechanic_UniGDEVMechanicCharacter_h__Script_UniGDEVMechanic_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
