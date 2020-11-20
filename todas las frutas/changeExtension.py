import os
from pathlib import Path

directory = r'D:\\Musica'
newExtension = '.wav'
for filename in os.listdir(directory):
    if filename.endswith(".m4a"):
        fileToRename = Path(directory+'\\'+filename)
        fileToRename.rename(fileToRename.with_suffix(newExtension))
    else:
        continue
