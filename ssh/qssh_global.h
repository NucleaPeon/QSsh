#ifndef SLESSH_GLOBAL_H
#define SLESSH_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SLESSH_LIBRARY)
#  define SLESSHSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SLESSHSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SLESSH_GLOBAL_H
