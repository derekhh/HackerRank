# pylint: disable=I0011,C0103

"""
This module generates a Markdown table from a HackerRank category.

Usage Example:
python table.py https://www.hackerrank.com/domains/algorithms/implementation

"""

import sys
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.ui import WebDriverWait
from urllib.parse import urljoin

driver = webdriver.PhantomJS()
delay = 10 # seconds
wait = WebDriverWait(driver, delay)

pageNum = 1
while True:
    suffix = "/page:" + str(pageNum)
    url = sys.argv[1] + suffix
    driver.get(url)
    try:
        wait.until(expected_conditions
                   .presence_of_all_elements_located((By.CSS_SELECTOR,
                                                      "a[data-analytics=\"ChallengeListChallengeName\"]")))
    except:
        break
    page = driver.page_source
    soup = BeautifulSoup(page, "lxml")
    challenges_list = soup.select('div.challenges-list > div.challenges-list-view')

    for challenges in challenges_list:
        challenge_name = challenges.select('a[data-analytics="ChallengeListChallengeName"]')
        assert len(challenge_name) <= 1
        if len(challenge_name) == 1:
            name = challenge_name[0].text.strip()
            href = challenge_name[0]['href']
            url = urljoin(url, href)
            source_name = href[href.rfind('/') + 1:] + '.cpp'

        footers = challenges.select('footer.track_content-footer span.msR')
        if len(footers) == 3:
            difficulty_text = footers[2].text.strip()
            difficulty = difficulty_text[difficulty_text.rfind(':') + 2:]
            print('|[%s](%s)|%s|%s|||||'%(name,url,source_name,difficulty))

    pageNum += 1
