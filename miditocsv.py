import py_midicsv as pm

# Load the MIDI file and parse it into CSV format
csv_string = pm.midi_to_csv("./todas las frutas/Valentine_-_Laufey_Arrangement_for_Solo_Piano.mid")

#with open("example_converted.csv", "w") as f:
#    f.writelines(csv_string)
