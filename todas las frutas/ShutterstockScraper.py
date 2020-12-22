from selenium import webdriver
import requests
import urllib.request
from selenium.webdriver.common.keys import Keys

def download_image(url,name,path):
    fullPath = path+str(name)+'.jpg'
    urllib.request.urlretrieve(url,fullPath)  

#please change this path to where your driver is installed, in my case it is chromedriver.exe
browser = webdriver.Chrome(executable_path=r'D:\chromedriver_win3279\chromedriver.exe')

browser.get('http://image-net.org/login')
usernameField = browser.find_element_by_name("username")
passwordField = browser.find_element_by_name("password")

username = "A01197044"
password = "A01197044"

usernameField.send_keys(username)

passwordField.send_keys(password)
passwordField.send_keys(Keys.RETURN)

searchField = browser.find_element_by_name("q")
wordToSearch = "dog"

searchField.send_keys(wordToSearch)
searchField.send_keys(Keys.RETURN)

link_tags = browser.find_elements_by_tag_name('a')

hrefs = []
wnids = []

for tag in link_tags:
    toAppend = tag.get_attribute('href')
    if("wnid" in toAppend):
        print(toAppend)
        corte = toAppend.find('=')
        wnid = toAppend[corte+1:]
        wnids.append(wnid)
        hrefs.append(toAppend)

leftUrl = "http://www.image-net.org/api/text/imagenet.synset.geturls?wnid="

browser.get(leftUrl + wnids[0])

imageLinks = browser.find_elements_by_tag_name('pre')

r = requests.get(leftUrl + wnids[0])
links = (r.text).splitlines()
print(len(links))

identifier = 1

for urls in links:
    try:
        #please change this path to where you want to save your pictures before counting them
        download_image(urls,identifier,'C:\\Users\\pcruiher08\\Desktop\\ImageNet-WebScraper\\rawImages\\')
        identifier = identifier + 1
    except:
        print("no can't do") 
