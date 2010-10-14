import os

from google.appengine.ext import webapp
from google.appengine.ext.webapp import template
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.api import urlfetch

class MainPage(webapp.RequestHandler):
    def get(self):
        path = os.path.join(os.path.dirname(__file__), 'index.html')
        self.response.out.write(template.render(path, {}))

    def post(self):
        pass

class QueryIP(webapp.RequestHandler):
    def get(self):
        ip = self.request.get('ip')
        url = "http://link.myclover.org/Hack/Script/big_brother/ip/" + ip + ".html"
        result = urlfetch.fetch(url)
        if result.status_code == 200:
            self.response.out.write(result.content)

    def post(post):
        pass

application = webapp.WSGIApplication([('/', MainPage),
                                      ('/query', QueryIP)],
                                     debug=False)

def main():
    run_wsgi_app(application)

if __name__ == "__main__":
    main()
