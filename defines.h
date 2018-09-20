/*
 * File: defines.h
 */
 
#pragma once

// Debug mode: verbose output for debugging purposes
#define DEBUG_MODE false

// Is the current machine running a Windows OS?
// Used to determine file structure format
#define WINDOWS true

#if DEBUG_MODE

  // Remove the extraneous file structure from __FILE__
  #if WINDOWS
    #define FILENAME (strrchr(__FILE__, '\\') ? \
      strrchr(__FILE__, '\\') + 1 : __FILE__)
  #else
    #define FILENAME (strrchr(__FILE__, '/') ? \
      strrchr(__FILE__, '/') + 1 : __FILE__)
  #endif // WINDOWS

  // Debug Function Calls
  // Show the file name, line number, function name
  // and time from wherever this macro is placed
  #define DFC                           \
      Serial.print(F("DFC (File:"));    \
      Serial.print(FILENAME);           \
      Serial.print(F("   Line:"));      \
      Serial.print(__LINE__);           \
      Serial.print(F("   Function:"));  \
      Serial.print(__FUNCTION__);       \
      Serial.println(F(")"));           \
      Serial.flush()

#else

#define DFC do {} while (false)

#endif // DEBUG_MODE
