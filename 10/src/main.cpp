#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using std::cout;
using std::string;
using std::unordered_map;
using std::vector;

int MultiplyByTwo(int &i)
{
  i = 2 * i;
  return i;
}

int main()
{
  {
    int a = 5;
    cout << "The int a equals: " << a << "\n";
    int b = MultiplyByTwo(a);
    cout << "The int b equals: " << b << "\n";
    cout << "The int a now equals: " << a << "\n";

    int i{1};

    // Declare a reference to i.
    int &j = i;
    cout << "The value of j is: " << j << "\n";

    // Change the value of i.
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";

    // Change the value of the reference.
    // Since reference is just another name for the variable,
    // th
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";
  }
  {
    int i = 5;
    int j = 6;

    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";
  }
  {
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int *pointer_to_i = &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    cout << "The value of the variable pointer_to_i is: " << *pointer_to_i << "\n";
  }
  {
    // Vector v is declared and initialized to {1, 2, 3}
    vector<int> v{1, 2, 3};

    // Declare and initialize a pointer to the address of v here:
    vector<int> *pointer_to_v = &v;

    // The following loops over each int a in the vector v and prints.
    // Note that this uses a "range-based" for loop:
    // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-for-range
    for (int a : v)
    {
      cout << a << "\n";
    }

    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    cout << "The second element of v is: " << *(&(*pointer_to_v)[0] + 0x0) << "\n";
    cout << "The second element of v is: " << *(&(*pointer_to_v)[1] + 0x0) << "\n";
    cout << "The second element of v is: " << *(&(*pointer_to_v)[0] + 0x2) << "\n";
  }
  {
    // Create strings to use in the hash table.
    int prefix = 960;
    unordered_map<int, string> country_prefixes{{972, "Israel"}, {93, "Afghanistan"}, {355, "Albania"}, {213, "Algeria"}, {376, "Andorra"}, {244, "Angola"}, {54, "Argentina"}, {374, "Armenia"}, {297, "Aruba"}, {61, "Australia"}, {43, "Austria"}, {994, "Azerbaijan"}, {973, "Bahrain"}, {880, "Bangladesh"}, {375, "Belarus"}, {32, "Belgium"}, {501, "Belize"}, {229, "Benin"}, {975, "Bhutan"}, {387, "Bosnia and Herzegovina"}, {267, "Botswana"}, {55, "Brazil"}, {246, "British Indian Ocean Territory"}, {359, "Bulgaria"}, {226, "Burkina Faso"}, {257, "Burundi"}, {855, "Cambodia"}, {237, "Cameroon"}, {1, "Canada"}, {238, "Cape Verde"}, {236, "Central African Republic"}, {235, "Chad"}, {56, "Chile"}, {86, "China"}, {61, "Christmas Island"}, {57, "Colombia"}, {269, "Comoros"}, {242, "Congo"}, {682, "Cook Islands"}, {506, "Costa Rica"}, {385, "Croatia"}, {53, "Cuba"}, {537, "Cyprus"}, {420, "Czech Republic"}, {45, "Denmark"}, {253, "Djibouti"}, {593, "Ecuador"}, {20, "Egypt"}, {503, "El Salvador"}, {240, "Equatorial Guinea"}, {291, "Eritrea"}, {372, "Estonia"}, {251, "Ethiopia"}, {298, "Faroe Islands"}, {679, "Fiji"}, {358, "Finland"}, {33, "France"}, {594, "French Guiana"}, {689, "French Polynesia"}, {241, "Gabon"}, {220, "Gambia"}, {995, "Georgia"}, {49, "Germany"}, {233, "Ghana"}, {350, "Gibraltar"}, {30, "Greece"}, {299, "Greenland"}, {590, "Guadeloupe"}, {502, "Guatemala"}, {224, "Guinea"}, {245, "Guinea-Bissau"}, {595, "Guyana"}, {509, "Haiti"}, {504, "Honduras"}, {36, "Hungary"}, {354, "Iceland"}, {91, "India"}, {62, "Indonesia"}, {964, "Iraq"}, {353, "Ireland"}, {972, "Israel"}, {39, "Italy"}, {81, "Japan"}, {962, "Jordan"}, {254, "Kenya"}, {686, "Kiribati"}, {965, "Kuwait"}, {996, "Kyrgyzstan"}, {371, "Latvia"}, {961, "Lebanon"}, {266, "Lesotho"}, {231, "Liberia"}, {423, "Liechtenstein"}, {370, "Lithuania"}, {352, "Luxembourg"}, {261, "Madagascar"}, {265, "Malawi"}, {60, "Malaysia"}, {223, "Mali"}, {356, "Malta"}, {692, "Marshall Islands"}, {596, "Martinique"}, {222, "Mauritania"}, {230, "Mauritius"}, {262, "Mayotte"}, {52, "Mexico"}, {377, "Monaco"}, {976, "Mongolia"}, {382, "Montenegro"}, {212, "Morocco"}, {95, "Myanmar"}, {264, "Namibia"}, {674, "Nauru"}, {977, "Nepal"}, {31, "Netherlands"}, {599, "Netherlands Antilles"}, {687, "New Caledonia"}, {64, "New Zealand"}, {505, "Nicaragua"}, {227, "Niger"}, {234, "Nigeria"}, {683, "Niue"}, {672, "Norfolk Island"}, {47, "Norway"}, {968, "Oman"}, {92, "Pakistan"}, {680, "Palau"}, {507, "Panama"}, {675, "Papua New Guinea"}, {595, "Paraguay"}, {51, "Peru"}, {63, "Philippines"}, {48, "Poland"}, {351, "Portugal"}, {974, "Qatar"}, {40, "Romania"}, {250, "Rwanda"}, {685, "Samoa"}, {378, "San Marino"}, {966, "Saudi Arabia"}, {221, "Senegal"}, {381, "Serbia"}, {248, "Seychelles"}, {232, "Sierra Leone"}, {65, "Singapore"}, {421, "Slovakia"}, {386, "Slovenia"}, {677, "Solomon Islands"}, {27, "South Africa"}, {500, "South Georgia and the South Sandwich Islands"}, {34, "Spain"}, {94, "Sri Lanka"}, {249, "Sudan"}, {597, "Suriname"}, {268, "Swaziland"}, {46, "Sweden"}, {41, "Switzerland"}, {992, "Tajikistan"}, {66, "Thailand"}, {228, "Togo"}, {690, "Tokelau"}, {676, "Tonga"}, {216, "Tunisia"}, {90, "Turkey"}, {993, "Turkmenistan"}, {688, "Tuvalu"}, {256, "Uganda"}, {380, "Ukraine"}, {971, "United Arab Emirates"}, {44, "United Kingdom"}, {1, "United States"}, {598, "Uruguay"}, {998, "Uzbekistan"}, {678, "Vanuatu"}, {681, "Wallis and Futuna"}, {967, "Yemen"}, {260, "Zambia"}, {263, "Zimbabwe"}, {591, "Bolivia, Plurinational State of"}, {673, "Brunei Darussalam"}, {61, "Cocos (Keeling) Islands"}, {243, "Congo, The Democratic Republic of the"}, {225, "Cote dIvoire"}, {500, "Falkland Islands (Malvinas)"}, {44, "Guernsey"}, {379, "Holy See (Vatican City State)"}, {852, "Hong Kong"}, {98, "Iran, Islamic Republic of"}, {44, "Isle of Man"}, {44, "Jersey"}, {850, "Korea, Democratic People's Republic of"}, {82, "Korea, Republic of"}, {856, "Lao People's Democratic Republic"}, {218, "Libyan Arab Jamahiriya"}, {853, "Macao"}, {389, "Macedonia, The Former Yugoslav Republic of"}, {691, "Micronesia, Federated States of"}, {373, "Moldova, Republic of"}, {258, "Mozambique"}, {970, "Palestinian Territory, Occupied"}, {872, "Pitcairn"}, {262, "Réunion"}, {7, "Russia"}, {590, "Saint Barthélemy"}, {290, "Saint Helena, Ascension and Tristan Da Cunha"}, {590, "Saint Martin"}, {508, "Saint Pierre and Miquelon"}, {239, "Sao Tome and Principe"}, {252, "Somalia"}, {47, "Svalbard and Jan Mayen"}, {963, "Syrian Arab Republic"}, {886, "Taiwan, Province of China"}, {255, "Tanzania, United Republic of"}, {670, "Timor-Leste"}, {58, "Venezuela, Bolivarian Republic of"}, {84, "Viet Nam"}};

    // Check if key is in the hash table.
    if (country_prefixes.find(prefix) == country_prefixes.end())
    {
      cout << "The prefix '" << prefix << "' is not in the list of prefixes."
           << "\n";
      cout << "Inserting the prefix-country pair into the dictionary."
           << "\n\n";
      // Set the value for the key.
      country_prefixes[prefix] = "Maldives";
    }

    // The prefix should now be in the country_prefixes unordered_map. We can access the
    // country corresponding to the prefix with square brackets [].
    // Here, the country country_prefixes[prefix] is a string.
    // We simply print the string.
    cout << prefix << ": \n";
    string country = country_prefixes[prefix];
    cout << country << "\n";
  }
}