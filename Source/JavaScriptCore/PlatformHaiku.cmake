include(inspector/remote/Socket.cmake)

list(APPEND JavaScriptCore_PUBLIC_FRAMEWORK_HEADERS
    API/JSStringRefBSTR.h
    API/JavaScriptCore.h
)

install(FILES API/JavaScript.h
              API/JSBase.h
              API/JSContextRef.h
              API/JSObjectRef.h
              API/JSStringRef.h
              API/JSValueRef.h
              API/WebKitAvailability.h
        DESTINATION "${HEADER_INSTALL_DIR}/JavaScriptCore"
)

list(APPEND JavaScriptCore_LIBRARIES
	network
)
