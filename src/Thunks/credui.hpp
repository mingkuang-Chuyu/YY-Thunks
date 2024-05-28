﻿
#include <wincred.h>

namespace YY
{
	namespace Thunks
	{

#if (YY_Thunks_Support_Version < NTDDI_WIN6)

        // 最低受支持的客户端	Windows Vista [仅限桌面应用]
        // 最低受支持的服务器	Windows Server 2008[仅限桌面应用]
		__DEFINE_THUNK(
        credui,
		36,
        DWORD,
        WINAPI,
        CredUIPromptForWindowsCredentialsW,
            _In_opt_ PCREDUI_INFOW pUiInfo,
            _In_ DWORD dwAuthError,
            _Inout_ ULONG* pulAuthPackage,
            _In_reads_bytes_opt_(ulInAuthBufferSize) LPCVOID pvInAuthBuffer,
            _In_ ULONG ulInAuthBufferSize,
            _Outptr_result_bytebuffer_to_(*pulOutAuthBufferSize, *pulOutAuthBufferSize) LPVOID* ppvOutAuthBuffer,
            _Out_ ULONG* pulOutAuthBufferSize,
            _Inout_opt_ BOOL* pfSave,
            _In_ DWORD dwFlags
		    )
		{
			if (auto const _pfnCredUIPromptForWindowsCredentialsW = try_get_CredUIPromptForWindowsCredentialsW())
			{
				return _pfnCredUIPromptForWindowsCredentialsW(pUiInfo, dwAuthError, pulAuthPackage, pvInAuthBuffer, ulInAuthBufferSize, ppvOutAuthBuffer,
                    pulOutAuthBufferSize, pfSave, dwFlags);
			}

			return ERROR_CANCELLED;
		}
#endif

		
		

	}//namespace Thunks

} //namespace YY
