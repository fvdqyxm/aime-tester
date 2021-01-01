from bs4 import BeautifulSoup
from bs4.element import Comment
import urllib.request


def tag_visible(element):
    if element.parent.name in ['style', 'script', 'head', 'title', 'meta', '[document]']:
        return False
    if isinstance(element, Comment):
        return False
    return True


def text_from_html(body):
    soup = BeautifulSoup(body, 'html.parser')
    texts = soup.findAll(text=True)
    visible_texts = filter(tag_visible, texts)  
    return u" ".join(t.strip() for t in visible_texts)
for i in range(2000, 2021):

    html = urllib.request.urlopen(f'https://artofproblemsolving.com/wiki/index.php/{i}_AIME_I_Answer_Key').read()
    # html = urllib.request.urlopen('https://artofproblemsolving.com/wiki/index.php/1983_AIME_Answer_Key').read()
    with open(f'{i}_I.txt', 'w') as f: 
        print(text_from_html(html), file=f)
    html2 = urllib.request.urlopen(f'https://artofproblemsolving.com/wiki/index.php/{i}_AIME_II_Answer_Key').read()
    with open(f'{i}_II.txt', 'w') as f:
        print(text_from_html(html2), file=f)
