from logging import Logger, basicConfig, getLogger
from os import getenv, path, listdir
from shutil import copy

FAILE_PATH = 'library'
OTERA_PATH = 'otera'

logger = getLogger(__name__)  # type: Logger

class Generator:
    def __init__(self):
        pass

    def generate(self, lib_path, file_name, otera_path):
        print("generate: " + file_name)
        copy(lib_path, otera_path + '/' + file_name)

    def file_check(self, lib_path, file_name):
        if path.isdir(lib_path):
            files = listdir(lib_path)
            for file in files:
                self.file_check(lib_path + '/' + file, file)

        else:
            if lib_path[-4:] == '.hpp':
                self.generate(lib_path, file_name, OTERA_PATH)

if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    generator = Generator()
    generator.file_check(FAILE_PATH, '')