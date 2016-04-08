
#if _DEBUG
#pragma comment(lib, "wxbase28ud.lib")
#pragma comment(lib, "wxmsw28ud_core.lib")
#pragma comment(lib, "wxbase28ud_xml.lib")
#pragma comment(lib, "wxmsw28ud_adv.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iced.lib")
#pragma comment(lib, "iceutild.lib")

#else

#pragma comment(lib, "wxbase28u.lib")
#pragma comment(lib, "wxmsw28u_core.lib")
#pragma comment(lib, "wxbase28u_xml.lib")
#pragma comment(lib, "wxmsw28u_adv.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "ice.lib")
#pragma comment(lib, "iceutil.lib")
#endif