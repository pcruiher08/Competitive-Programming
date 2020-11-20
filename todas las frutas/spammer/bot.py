
# -*- coding: utf-8 -*-

import pyautogui, time, pyperclip
time.sleep(3)

f = open("NocturnoEnQueNadaSeOye.txt", encoding="utf-8")
text = ""
print("start")
for word in f: 
    #word = word.decode('quopri').decode('utf-8')
    text += (word)
    #pyautogui.typewrite(word)
pyperclip.copy(text)
pyautogui.hotkey("ctrl",'v')
pyautogui.press("enter")