// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INKING_INKINGCharacter_generated_h
#error "INKINGCharacter.generated.h already included, missing '#pragma once' in INKINGCharacter.h"
#endif
#define INKING_INKINGCharacter_generated_h

#define INKING_Source_INKING_INKINGCharacter_h_12_SPARSE_DATA
#define INKING_Source_INKING_INKINGCharacter_h_12_RPC_WRAPPERS
#define INKING_Source_INKING_INKINGCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define INKING_Source_INKING_INKINGCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAINKINGCharacter(); \
	friend struct Z_Construct_UClass_AINKINGCharacter_Statics; \
public: \
	DECLARE_CLASS(AINKINGCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/INKING"), NO_API) \
	DECLARE_SERIALIZER(AINKINGCharacter)


#define INKING_Source_INKING_INKINGCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAINKINGCharacter(); \
	friend struct Z_Construct_UClass_AINKINGCharacter_Statics; \
public: \
	DECLARE_CLASS(AINKINGCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/INKING"), NO_API) \
	DECLARE_SERIALIZER(AINKINGCharacter)


#define INKING_Source_INKING_INKINGCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AINKINGCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AINKINGCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AINKINGCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AINKINGCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AINKINGCharacter(AINKINGCharacter&&); \
	NO_API AINKINGCharacter(const AINKINGCharacter&); \
public:


#define INKING_Source_INKING_INKINGCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AINKINGCharacter(AINKINGCharacter&&); \
	NO_API AINKINGCharacter(const AINKINGCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AINKINGCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AINKINGCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AINKINGCharacter)


#define INKING_Source_INKING_INKINGCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AINKINGCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AINKINGCharacter, FollowCamera); }


#define INKING_Source_INKING_INKINGCharacter_h_9_PROLOG
#define INKING_Source_INKING_INKINGCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	INKING_Source_INKING_INKINGCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	INKING_Source_INKING_INKINGCharacter_h_12_SPARSE_DATA \
	INKING_Source_INKING_INKINGCharacter_h_12_RPC_WRAPPERS \
	INKING_Source_INKING_INKINGCharacter_h_12_INCLASS \
	INKING_Source_INKING_INKINGCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define INKING_Source_INKING_INKINGCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	INKING_Source_INKING_INKINGCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	INKING_Source_INKING_INKINGCharacter_h_12_SPARSE_DATA \
	INKING_Source_INKING_INKINGCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	INKING_Source_INKING_INKINGCharacter_h_12_INCLASS_NO_PURE_DECLS \
	INKING_Source_INKING_INKINGCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INKING_API UClass* StaticClass<class AINKINGCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID INKING_Source_INKING_INKINGCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
