// 15/03/2015

#include <AppleEfi.h>
#include <EfiDriverLib.h>

#include <IndustryStandard/AppleHid.h>

#include <Protocol/AppleKeyMapAggregator.h>

#include <Library/AppleKeyMapAggregatorLib.h>

// mAppleKeyMapAggregator
APPLE_KEY_MAP_AGGREGATOR_PROTOCOL *mAppleKeyMapAggregator;

// GetAppleKeyStrokes
EFI_STATUS
GetAppleKeyStrokes (
	OUT APPLE_MODIFIER_MAP  *Modifiers,
	OUT UINTN               *NoKeys,
	OUT APPLE_KEY           **Keys
	) // sub_1015
{
	EFI_STATUS Status;

	Status = EFI_UNSUPPORTED;

	if (mAppleKeyMapAggregator != NULL) {
		Status = EFI_INVALID_PARAMETER;

		if ((Modifiers != NULL) && (NoKeys != NULL) && (Keys != NULL)) {
			*NoKeys = 0;
			*Keys   = NULL;
			Status  = mAppleKeyMapAggregator->GetKeyStrokes (mAppleKeyMapAggregator, Modifiers, NoKeys, NULL);

			if (Status == EFI_BUFFER_TOO_SMALL) {
				if (*NoKeys == 0) {
					*Keys = NULL;
				} else {
					*Keys = (APPLE_KEY *)EfiLibAllocatePool (*NoKeys * sizeof (**Keys));

					if (*Keys == NULL) {
						*NoKeys = 0;
						Status  = EFI_OUT_OF_RESOURCES;
					} else {
						Status = mAppleKeyMapAggregator->GetKeyStrokes (mAppleKeyMapAggregator, Modifiers, NoKeys, *Keys);

						if (EFI_ERROR (Status)) {
							gBS->FreePool ((VOID *)*Keys);

							*Keys   = NULL;
							*NoKeys = 0;
						}
					}
				}
			}
		}
	}

	return Status;
}

// GetModifierStrokes
APPLE_MODIFIER_MAP
GetModifierStrokes (
	VOID
	) // sub_FDA
{
	APPLE_MODIFIER_MAP Modifiers;

	EFI_STATUS         Status;
	UINTN              NoKeys;
	APPLE_KEY          *Keys;

	Status = GetAppleKeyStrokes (&Modifiers, &NoKeys, &Keys);

	if (!EFI_ERROR (Status)) {
		gBS->FreePool ((VOID *)Keys);
	} else {
		Modifiers = 0;
	}

	return Modifiers;
}
