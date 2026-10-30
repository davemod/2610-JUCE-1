#include <iostream>
#include <cassert>

double beatDurationMs (double bpm) 
{
    // C++ assertion, program stops if condition is false and can't be continued.
    assert (bpm > 0.); 

    // JUCE assertion, program stops if condition is false but can be continued afterwards
    // jassert (bpm > 0.); 

    if (bpm <= 0.0)
        return -1.0;

    return 60000.0 / bpm;
}

double twoBeatsMs (double bpm)
{
    assert (bpm > 0.);
    if (bpm <= 0.0)
        return -1.0;

    double oneBeat = beatDurationMs (bpm);
    return 2.0 * oneBeat;
}

double barDurationMs(int bpm, int beatsPerBar)
{
    double oneBeat = beatDurationMs(bpm);
    return beatsPerBar * oneBeat;
}

int main()
{      
    std::cout << "Time of one beat at 60 BPM: " << beatDurationMs (60.0) << " ms\n";
    std::cout << "Time of one beat at 120 BPM: " << beatDurationMs (120.0) << " ms\n";
    std::cout << "Time of one beat at 150 BPM: " << beatDurationMs (150.0) << " ms\n";

    std::cout << "Time of two beats at 60 BPM: " << twoBeatsMs (60.0) << " ms\n";
    std::cout << "Time of two beats at 120 BPM: " << twoBeatsMs (120.0) << " ms\n";
    std::cout << "Time of two beats at 150 BPM: " << twoBeatsMs (150.0) << " ms\n";

    // Local variables are only accessible within the scope where they are defined. Which is why we can't access the variable 'oneBeat' here, it is only defined in the function twoBeatsMs.

    std::cout << "Time of one bar at 60 BPM with 4 beats per bar: " << barDurationMs (60.0, 4) << " ms\n";
    std::cout << "Time of one bar at 120 BPM with 4 beats per bar: " << barDurationMs (120.0, 4) << " ms\n";
    std::cout << "Time of one bar at 150 BPM with 4 beats per bar: " << barDurationMs (150.0, 4) << " ms\n";

    return 0;
}
