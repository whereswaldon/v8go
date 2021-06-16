package v8go

// #include "v8go.h"
// #include <stdlib.h>
import "C"

// SetGLErrorCheckAndLog set the switch for whether do GL error check and log GL commands
func SetGLErrorCheckAndLog(checkError, logCommands bool) {
	checkErrorVal := 0
	if checkError {
		checkErrorVal = 1
	}
	logCommandsVal := 0
	if logCommands {
		logCommandsVal = 1
	}
	C.SetGLErrorCheckAndLog(C.int(checkErrorVal), C.int(logCommandsVal))
}
