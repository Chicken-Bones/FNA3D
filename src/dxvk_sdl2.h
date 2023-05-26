#ifndef DXVK_SDL2_H
#define DXVK_SDL2_H

#include <windows.h>

extern HRESULT dxvkInitWSI(void* factory);

#endif /* DXVK_SDL2_H */

#ifdef DXVK_SDL2_IMPL

#include <dxvk_wsi.h>

/* TODO: Define static functions for WSI vtable */

static const DxvkCustomWsi dxvk_sdl2_wsi = {
	NULL
};

HRESULT dxvkInitWSI(void* factory)
{
	IDxvkWsi *wsi;
	HRESULT res = IDXGIFactory1_QueryInterface(
		(IDXGIFactory1*) factory,
		&IID_IDxvkWsi,
		(void**) &wsi
	);
	if (FAILED(res))
	{
		return res;
	}

	return IDxvkWsi_SetWSI(wsi, &dxvk_sdl2_wsi);
}

#endif /* DXVK_SDL2_IMPL */
