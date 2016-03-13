from distutils.core import setup, Extension
setup(name='rect', version='1.0', ext_modules=[Extension('project',
						sources = ['Pypolyline.c'],
						include_dirs = ['/opt/vc/include','opt/vc/include/interface/vmcs_host/linux',
								'/opt/vc/include/interface/vcos/pthreads'],
						libraries = ['shapes'],
						library_dirs = ['/opt/vc/lib/'])])
