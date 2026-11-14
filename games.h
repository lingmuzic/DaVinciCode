#pragma once

// Each version of the game lives in its own .cpp file.
void run_v1();   // core logic + range check
void run_v2();   // + input validation, random phrases, win rating
void run_v3();   // + near-miss hints, no back-to-back repeats
