HPM_FILE_NAME="ninja.tar"
# HPM_NINJA_INSTALL 用户可在hpmrc中配置的 ninja安装地址 调用 卸载都依赖于该值

if [ ! ${HPM_NINJA_INSTALL} ]; then
    HPM_NINJA_INSTALL=${globalRepo}
fi

rm -rf ${HPM_NINJA_INSTALL}/ninja   

rm -rf ${HPM_NINJA_INSTALL}/ninja.exe

rm  ${HPM_FILE_NAME}
