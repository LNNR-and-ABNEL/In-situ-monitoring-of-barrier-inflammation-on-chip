# in-situ-monitoring-of-barrier-inflammation-on-chip

Python files for automated fiber photometry recording and analysis

For Arduino LED/Camera control:
Download the .ino file. This code outputs 5V from each pin to trigger the photometry CMOS cameras and LEDs together. A voltage divider or similar (via breadboard) is required to knock down the voltage signal sent to the LED driver.

For python analysis:
Download all .ipynb files to the same directory/folder. Photometry_Barrier_Function_Analysis.ipynb is the main file that has dependency on Locate_Fibers.ipynb and Analysis_Photometry_Image_Processing.ipynb.

Collect photometry data as images (.tiff or similar) and analyze using the Photometry_Barrier_Function_Analysis.ipynb file. Run the first cell in Photometry_Barrier_Function_Analysis.ipynb to ensure the correct file directories are used. The code will identify the fiber ends, analyze the image data for each fiber end, and write a .csv file containing dF/F and mean grey intensity values for each collected timepoint. 

Note: The image-containing folder must (currently) contain Apical and Basal subfolders containing images (FolderName/Apical/.tiff AND FolderName/Basal/.tiff).
