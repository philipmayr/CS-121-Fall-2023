#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

short find_int(short value, short list[], short len);
short find_char(short value, char list[], short len);

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

int main(void)
{
	char note_letters[7] = {'C', 'D', 'E', 'F', 'G', 'A', 'G'};
	short note_pitches[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "\n\t\tWelcome to the Tempered Scale Builder.\n\n";

	cout << "Choose tuning temperament, Twelve-Tone Equal Tempered or Pythagorean:\n"
		 << "Enter 'e' for Equal or 'p' for Pythagorean:\n";

	char choice;

	cin >> choice;

	cin.ignore(INF_FLAG, '\n');

	cout << "\nEnter scale starting note: (C0 to C9):\n";

	char starting_note_letter;
	short starting_pitch_num;

	cin >> starting_note_letter >> starting_pitch_num;

    if ((find_char(starting_note_letter, note_letters, 7) < 0 || find_int(starting_pitch_num, note_pitches, 10) < 0))
    {
        cout << "\nEntered note is out of bounds.";
    }

	cout << "\nEnter scale ending note: (C0 to C9): \n";

	char ending_note_letter;
	short ending_pitch_num;
	
	cin >> ending_note_letter >> ending_pitch_num;

    if ((find_char(ending_note_letter, note_letters, 7) < 0 || find_int(ending_pitch_num, note_pitches, 10) < 0))
    {
        cout << "\nEntered note is out of bounds.";
    }

    cout << "\n";
}

short find_char(short value, char list[], short len)
{
    for (short i = 0; i < len; i++)
    {
        if (list[i] == value)
        {
            return i;
        }
    }
    return -1;
}

short find_int(short value, short list[], short len)
{
	for (short i = 0; i < len; i++)
	{
		if (list[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void build_equal_tempered_scale(char starting_note_letter, 
                                short starting_note_pitch, 
                                char ending_note_letter, 
                                short ending_note_pitch,
                                short base_pitch,
                                short interval)
{
    short octave_distance;

    if (starting_note_pitch == 4)
    {
        octave_distance = 0;
    } else if (starting_note_pitch > 4)
    {
        octave_distance = starting_note_pitch - 4;
        for (short i = 0; i < octave_distance; i++)
        {
            starting_note_pitch * 2;
        } 
    } else if (starting_note_pitch < 4)
    {
        octave_distance = -(4 - starting_note_pitch);
        for (short i = 0; i < octave_distance; i++)
        {
            
        } 
    }
}

void build_pythagorean_tempered_scale(char starting_note_letter, 
                                short starting_note_pitch, 
                                char ending_note_letter, 
                                short ending_note_pitch,
                                short base_pitch,
                                short interval)
{
    
}
