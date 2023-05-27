from sclib import SoundcloudAPI, Track, Playlist
from sys import argv

if __name__ == '__main__':


    url = argv[1]
    isPlaylist = "sets" in url

    api = SoundcloudAPI()

    print(url)

    # assert type(playlist) is Playlist

    with open('temp.txt', 'a') as file:
        if isPlaylist:
            playlist = api.resolve(url)
            for track in playlist.tracks:
                filename = f'{track.artist};{track.title};2500\n'
                print(filename)
                file.write(filename)
        else:
            track = api.resolve(url)
            filename = f'{track.artist};{track.title};2500\n'
            file.write(filename)