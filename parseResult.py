import operator
import json


class Database:
    def __init__(self):
        self.DB = dict()

    # Read Old DB
    def readDB(self, file='database.json'):
        try:
            with open(file, 'r') as f:
                self.DB = json.load(f)
                f.close()
        except:
            print(f"No DB to read : {file}")

    # Write New DB
    def writeDB(self, file="database.json"):
        with open(file, 'w') as f:
            json.dump(self.DB, f, indent='\t')
            f.close()


result = Database()
result.readDB("result.json")

dbadv = Database()
dbbeg = Database()

liadv = ["ADV1", "ADV2", "ADV3", "ADV4", "ADV5", "ADV6"]
libeg = ["BEG1", "BEG2", "BEG3", "BEG4", "BEG5", "BEG6"]

for item in liadv:
    try:
        for key in list(result.DB[item].keys()):
            if key in dbadv.DB.keys():
                dbadv.DB[key] += result.DB[item][key]
            else:
                dbadv.DB[key] = result.DB[item][key]
    except:
        print(f"No Result Found with key {item}.")

dbadv.DB = sorted(dbadv.DB.items(), key=(lambda x: x[1]), reverse=True)
dbadv.writeDB("Advanced.json")

for item in libeg:
    try:
        for key in list(result.DB[item].keys()):
            if key in dbbeg.DB.keys():
                dbbeg.DB[key] += result.DB[item][key]
            else:
                dbbeg.DB[key] = result.DB[item][key]
    except:
        print(f"No Result Found with key {item}.")

dbbeg.DB = sorted(dbbeg.DB.items(), key=(lambda x: x[1]), reverse=True)
dbbeg.writeDB("Beginner.json")
