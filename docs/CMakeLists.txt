set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(docs
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include"
        event/event.h
        socket/listener.h
        socket/socket.h
        core/core.h
        event/event_data.h
        )
