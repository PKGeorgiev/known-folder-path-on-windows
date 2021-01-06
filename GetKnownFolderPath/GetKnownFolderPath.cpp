#include <iostream>
#include <string>
#include <Windows.h>
#include <shlobj_core.h>
#include <locale>
#include <codecvt>

using namespace std;

string getKnownFolderPath(GUID knownFolderId)
{
	PWSTR pszPath = nullptr;
	wstring result = L"";

	if (SHGetKnownFolderPath(knownFolderId, KF_FLAG_CREATE, nullptr, &pszPath) == S_OK)
	{
		result.assign(pszPath);
		CoTaskMemFree(pszPath);
	}

	return wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(result);
}

int main(int argc, char* argv[])
{
	// FOLDERID_Downloads
	// FOLDERID_Pictures
	// FOLDERID_Desktop
	// Full list here: https://docs.microsoft.com/en-us/windows/win32/shell/knownfolderid
	cout << getKnownFolderPath(FOLDERID_Documents);

	string s;

}