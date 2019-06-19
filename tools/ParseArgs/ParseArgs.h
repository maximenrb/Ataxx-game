#include <memory>

//
// Created by Max on 19/05/2019.
//

#ifndef MINI_PROJECT_PARSEARGS_H
#define MINI_PROJECT_PARSEARGS_H

#include <string>
#include <list>
#include <map>
#include <memory>

#include "getoptpp/getopt_pp.h"

using std::shared_ptr;

using namespace GetOpt;
using namespace std;

class ArgModel {
private:
    char shortArg;
    string longArg;
    string defaultValue;
    list<string> acceptableValues;

public:
    ArgModel(const string &defaultValue, const list<string> &acceptableValues, const string &longArg, const char &shortArg = '0')
            : shortArg(shortArg), longArg(longArg), defaultValue(defaultValue), acceptableValues(acceptableValues) {

    }

    const char &getShortArg() const { return shortArg; }
    const string &getLongArg() const { return longArg; }
    const string &getDefaultValue() const { return defaultValue; }
    const list<string> &getAcceptableValues() const { return acceptableValues; }
};

class ParseArgs {
private:
    list<shared_ptr<ArgModel>> argList;

public:
    ParseArgs() {}

    void addArg(const string &defaultValue, const list<string> &acceptableValues, const string &longArg, const char &shortArg = '0') {
        argList.push_back(std::make_shared<ArgModel>(defaultValue, acceptableValues , longArg, shortArg));
    }

    void getArgMap(int argc, char *argv[], map<string, string> &argMap) {
        GetOpt_pp ops(argc, argv);

        for(auto &arg : argList) {
            string value;
            const string& argument = arg->getLongArg();

            argMap.insert( std::pair<string, string> (argument, arg->getDefaultValue()) );

            if(arg->getShortArg() == '0') {
                ops >> Option(argument, value, arg->getDefaultValue());
            } else {
                ops >> Option(arg->getShortArg(), argument, value, arg->getDefaultValue());
            }

            for(auto &acceptableValue : arg->getAcceptableValues()) {
                if(value == acceptableValue) {
                    argMap[argument] = value;
                }
            }
        }
    }

    virtual ~ParseArgs() {}
};

#endif //MINI_PROJECT_PARSEARGS_H
