#ifndef IL2CPP_INTERNALS_H
#define IL2CPP_INTERNALS_H
#include <stdint.h>
#define IL2CPP_ZERO_LEN_ARRAY 0

struct MethodInfo;
struct Il2CppClass;
typedef void(*Il2CppMethodPointer)();
typedef wchar_t Il2CppChar;
typedef const struct ___Il2CppMetadataGenericContainerHandle* Il2CppMetadataGenericContainerHandle;
typedef const struct ___Il2CppMetadataMethodHandle* Il2CppMetadataMethodDefinitionHandle;

// Corresponds to element type signatures
// See ECMA-335, II.23.1.16

typedef enum Il2CppTypeEnum
{
    IL2CPP_TYPE_END = 0x00,       /* End of List */
    IL2CPP_TYPE_VOID = 0x01,
    IL2CPP_TYPE_BOOLEAN = 0x02,
    IL2CPP_TYPE_CHAR = 0x03,
    IL2CPP_TYPE_I1 = 0x04,
    IL2CPP_TYPE_U1 = 0x05,
    IL2CPP_TYPE_I2 = 0x06,
    IL2CPP_TYPE_U2 = 0x07,
    IL2CPP_TYPE_I4 = 0x08,
    IL2CPP_TYPE_U4 = 0x09,
    IL2CPP_TYPE_I8 = 0x0a,
    IL2CPP_TYPE_U8 = 0x0b,
    IL2CPP_TYPE_R4 = 0x0c,
    IL2CPP_TYPE_R8 = 0x0d,
    IL2CPP_TYPE_STRING = 0x0e,
    IL2CPP_TYPE_PTR = 0x0f,       /* arg: <type> token */
    IL2CPP_TYPE_BYREF = 0x10,       /* arg: <type> token */
    IL2CPP_TYPE_VALUETYPE = 0x11,       /* arg: <type> token */
    IL2CPP_TYPE_CLASS = 0x12,       /* arg: <type> token */
    IL2CPP_TYPE_VAR = 0x13,       /* Generic parameter in a generic type definition, represented as number (compressed unsigned integer) number */
    IL2CPP_TYPE_ARRAY = 0x14,       /* type, rank, boundsCount, bound1, loCount, lo1 */
    IL2CPP_TYPE_GENERICINST = 0x15,     /* <type> <type-arg-count> <type-1> \x{2026} <type-n> */
    IL2CPP_TYPE_TYPEDBYREF = 0x16,
    IL2CPP_TYPE_I = 0x18,
    IL2CPP_TYPE_U = 0x19,
    IL2CPP_TYPE_FNPTR = 0x1b,        /* arg: full method signature */
    IL2CPP_TYPE_OBJECT = 0x1c,
    IL2CPP_TYPE_SZARRAY = 0x1d,       /* 0-based one-dim-array */
    IL2CPP_TYPE_MVAR = 0x1e,       /* Generic parameter in a generic method definition, represented as number (compressed unsigned integer)  */
    IL2CPP_TYPE_CMOD_REQD = 0x1f,       /* arg: typedef or typeref token */
    IL2CPP_TYPE_CMOD_OPT = 0x20,       /* optional arg: typedef or typref token */
    IL2CPP_TYPE_INTERNAL = 0x21,       /* CLR internal type */

    IL2CPP_TYPE_MODIFIER = 0x40,       /* Or with the following types */
    IL2CPP_TYPE_SENTINEL = 0x41,       /* Sentinel for varargs method signature */
    IL2CPP_TYPE_PINNED = 0x45,       /* Local var that points to pinned object */

    IL2CPP_TYPE_ENUM = 0x55,        /* an enumeration */
    IL2CPP_TYPE_IL2CPP_TYPE_INDEX = 0xff        /* an index into IL2CPP type metadata table */
} Il2CppTypeEnum;

struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
};
struct Il2CppType
{
    //union
    //{
    //    // We have this dummy field first because pre C99 compilers (MSVC) can only initializer the first value in a union.
    //    void* dummy;
    //    TypeDefinitionIndex __klassIndex; /* for VALUETYPE and CLASS at startup */
    //    Il2CppMetadataTypeHandle typeHandle; /* for VALUETYPE and CLASS at runtime */
    //    const Il2CppType* type;   /* for PTR and SZARRAY */
    //    Il2CppArrayType* array; /* for ARRAY */
    //    //MonoMethodSignature *method;
    //    GenericParameterIndex __genericParameterIndex; /* for VAR and MVAR at startup */
    //    Il2CppMetadataGenericParameterHandle genericParameterHandle; /* for VAR and MVAR at runtime */
    //    Il2CppGenericClass* generic_class; /* for GENERICINST */
    //} data;
    void* data;
    unsigned int attrs : 16; /* param attributes or field flags */
    Il2CppTypeEnum type : 8;
    unsigned int num_mods : 5;  /* max 64 modifiers follow at the end */
    unsigned int byref : 1;
    unsigned int pinned : 1;  /* valid when included in a local var signature */
    unsigned int valuetype : 1;
    //MonoCustomMod modifiers [MONO_ZERO_LEN_ARRAY]; /* this may grow */
    unsigned int bits;
};
struct Il2CppObject
{
    Il2CppClass* klass;
    void* monitor;
};
union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
};
struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
};
struct Il2CppClass_1
{
    void* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    void* generic_class;
    void* typeMetadataHandle;
    void* interopData;
    Il2CppClass* klass;
    void* fields;
    void* events;
    void* properties;
    void* methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};
struct Il2CppClass_2
{
    Il2CppClass** typeHierarchy;
    void* unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    size_t cctor_thread;
    void* genericContainerHandle;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t bitflags1;
    uint8_t bitflags2;
};
struct Il2CppClass
{
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    VirtualInvokeData vtable[1];
};
typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
};
typedef void (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**, void*);
struct MethodInfo
{
    Il2CppMethodPointer methodPointer;
    Il2CppMethodPointer virtualMethodPointer;
    InvokerMethod invoker_method;
    const char* name;
    Il2CppClass* klass;
    const Il2CppType* return_type;
    const Il2CppType** parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const void* methodMetadataHandle;
    };
    union
    {
        const void* genericMethod;
        const void* genericContainerHandle;
    };
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t bitflags;
};
typedef struct Il2CppGenericInst
{
    uint32_t type_argc;
    const Il2CppType** type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
    /* The instantiation corresponding to the class generic parameters */
    const Il2CppGenericInst* class_inst;
    /* The instantiation corresponding to the method generic parameters */
    const Il2CppGenericInst* method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericMethod
{
    const MethodInfo* methodDefinition;
    Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppString
{
    Il2CppObject object;
    int32_t length;                             ///< Length of string *excluding* the trailing null (which is included in 'chars').
    Il2CppChar chars[IL2CPP_ZERO_LEN_ARRAY];
} Il2CppString;

#endif