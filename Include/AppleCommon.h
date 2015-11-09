#ifndef _APPLE_COMMON_H_
#define _APPLE_COMMON_H_

#ifdef EFI_FORWARD_DECLARATION
  #define FORWARD_DECLARATION(x) EFI_FORWARD_DECLARATION (x)
#else
#if defined (EFI_NO_INTERFACE_DECL) || defined (NO_INTERFACE_DECL)
  #define FORWARD_DECLARATION(x)
#else
  #define FORWARD_DECLARATION(x) typedef struct _##x x
#endif // ifdef (EFI_NO_INTERFACE_DECL || NO_INTERFACE_DECL)
  #define EFI_FORWARD_DECLARATION(x) FORWARD_DECLARATION (x)
#endif // ifdef EFI_FORWARD_DECLARATION

// ARRAY_LENGTH
#define ARRAY_LENGTH(Array) (sizeof (Array) / sizeof (*(Array)))

// CONVERT_LENGTH
#define CONVERT_LENGTH(Size, SourceType, DestinationType) (((Size) / sizeof (SourceType)) * sizeof (DestinationType))

// BIT
#define BIT(Index)                (1 << (Index))
#define JOIN_MASKS(Mask1, Mask2)  ((Mask1) | (Mask2))
#define JOIN_BITS(Mask1, Mask2)   JOIN_MASKS ((Mask1), (Mask2))
#define SET_BIT(Mask1, Mask2)     JOIN_MASKS ((Mask1), (Mask2))
#define SET_BITS(Mask1, Mask2)    SET_BIT ((Mask1), (Mask2))
#define UNSET_BITS(Mask1, Mask2)  ((Mask1) & ~(Mask2))
#define UNSET_BIT(Mask1, Mask2)   UNSET_BITS ((Mask1), (Mask2))
#define DIFF_BITS(Mask1, Mask2)   ((Mask1) ^ (Mask2))
#define TOGGLE_BITS(Mask1, Mask2) DIFF_BITS ((Mask1), (Mask2))
#define TOGGLE_BIT(Mask1, Mask2)  TOGGLE_BITS ((Mask1), (Mask2))
#define APPLY_MASK(Mask1, Mask2)  ((Mask1) & (Mask2))
#define SELECT_BITS(Mask1, Mask2) APPLY_MASK ((Mask1), (Mask2))
#define BIT_SET(Mask1, Mask2)     ((BOOLEAN)(SELECT_BITS ((Mask1), (Mask2)) != 0))
#define BITS_SET(Mask1, Mask2)    ((BOOLEAN)(SELECT_BITS ((Mask1), (Mask2)) == (Mask2)))

#endif // ifndef _APPLE_COMMON_H_
