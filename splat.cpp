/*
 * Copyright 2018 by Philip N. Garner
 *
 * See the file COPYING for the licence associated with this software.
 *
 * Author(s):
 *   Phil Garner, October 2018
 */

#include <fstream>
#include <lube.h>
#include <lube/config.h>

namespace libube
{
    class Lexicon
    {
    public:
        //Lexicon();
        void read(var iFile);
        var phones();
        int size() { return mLex.size(); }
    private:
        var mLex;
    };
}

using namespace std;
using namespace libube;

void Lexicon::read(var iFile)
{
    // Open file
    std::ifstream is(iFile.str(), std::ifstream::in);
    if (is.fail())
        throw error("Lexicon::read(): Open failed");

    // Loop over lines
    var f;
    while (f.getline(is))
    {
        var a = f.split();
        var w = a.shift();
        mLex[w].push(a);
    }
    return;
}

var Lexicon::phones()
{
    var phone;
    for (int w=0; w<mLex.size(); w++)
    {
        var word = mLex[w];
        for (int p=0; p<word.size(); p++)
        {
            var pron = word[p];
            for (int i=0; i<pron.size(); i++)
            {
                var ph = pron[i];
                if (phone.index(ph))
                    phone[ph] += 1;
                else
                    phone[ph] = 1;
            }
        }
    }

    var keys;
    for (int i=0; i<phone.size(); i++)
        keys.push(phone.key(i));

    return keys;
}

int main(int argc, char** argv)
{
    // Options
    lube::Option opt("splat: Speech processor");
    opt('l', "Read lexicon", "");
    opt.parse(argc, argv);

    // Lexicon
    lube::Lexicon lex;
    if (opt['l'] != "")
    {
        lex.read(opt['l']);
        cout << "Lexicon has " << lex.size() << " words" << endl;
        var p = lex.phones();
        cout << "Phone list: " << p << endl;
    }
    return 0;
}
