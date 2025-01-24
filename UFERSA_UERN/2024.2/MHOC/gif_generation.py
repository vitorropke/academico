import os
from io import BytesIO

from PIL import Image
from matplotlib import pyplot as plt

OUTPUT = 'grafos/simulated_annealing/graph.gif'


def generate_gif_from_files():
    # Directory containing the images
    image_directory = 'grafos/simulated_annealing'

    # Get a sorted list of image file paths
    images = [os.path.join(image_directory, file) for file in sorted(os.listdir(image_directory)) if
              file.endswith(('png', 'jpg', 'jpeg'))]

    # Load images
    image_frames = [Image.open(img) for img in images]

    generate_gif(image_frames)


def generate_gif_from_plt(graph_plots):
    pillow_images = []
    for fig in graph_plots:
        buf = BytesIO()  # Create an in-memory bytes buffer
        fig.savefig(buf, format='jpg')  # Save the figure as a PNG to the buffer
        buf.seek(0)  # Rewind the buffer to the beginning
        img = Image.open(buf).copy()  # Open the image with Pillow
        pillow_images.append(img)
        buf.close()
        plt.close(fig)

    generate_gif(pillow_images)


def generate_gif(images):
    # Add the final frame multiple times.
    final_frame_repeats = 40
    extended_images = images + [images[-1]] * final_frame_repeats

    # Save as GIF
    images[0].save(
        OUTPUT,
        format='GIF',
        append_images=images[1:],  # Add the other images
        save_all=True,  # Save all frames
        duration=100,  # Frame duration in milliseconds
        loop=0  # Loop count, 0 for infinite loop
    )
